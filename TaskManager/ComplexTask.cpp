#include "ComplexTask.h"

ComplexTask::ComplexTask() : Task() {}

ComplexTask::~ComplexTask()
{
	for (unsigned i = 0; i < this->tasks.size(); i++)
	{
		ComplexTask *CT = dynamic_cast<ComplexTask*>(this->tasks[i]);
		if (CT)
		{
			CT->~ComplexTask();
			delete (tasks[i]);
		}
		else
		{
			delete (tasks[i]);
		}
	}
	tasks.clear();
}

ComplexTask::ComplexTask(const ComplexTask & c) : Task(c), tasks(c.tasks.size())
{
	for (unsigned i = 0; i < tasks.size(); i++)
	{
		tasks[i] = c.tasks[i]->clone();
	}
}

ComplexTask & ComplexTask::operator=(const ComplexTask & c)
{
	if (this != &c)
	{
		for (unsigned i = 0; i < tasks.size(); i++)
		{
			delete tasks[i];
		}
		tasks.clear();
		tasks.resize(c.tasks.size());

		for (unsigned i = 0; i < tasks.size(); i++)
		{
			tasks[i] = c.tasks[i]->clone();
		}
	}
	return *this;
}

void ComplexTask::addTask(Task* task)
{
	double prevSize = getSize();
	tasks.push_back(task->clone());
	setDescription(getDescription() + ' ' + task->getDescription());
	setSize(getSize() + task->getSize());
	setProgress((getProgress()*prevSize + task->getSize()*task->getProgress()) / getSize());

}

void ComplexTask::removeTask(const int index)
{
	if (index > (int)tasks.size() || index < 0) return;

	setSize(getSize() - tasks[index]->getSize());
	delete tasks[index];
	tasks.erase(tasks.begin() + index);

	setDescription("");
	for (unsigned i = 0; i < tasks.size(); i++)
	{
		setDescription(getDescription() + tasks[i]->getDescription());
	}
}

const double ComplexTask::Work(const double workSize)
{
	if (getIsComplete())
	{
		return workSize;
	}
	else
	{
		double currSize = getSize()*(1 - getProgress());
		if (currSize > workSize)
		{
			setProgress(getProgress() + workSize / getSize());
			return 0;
		}
		else
		{
			setProgress(1);
			setIsComplete();
			return workSize - currSize;
		}
	}
}

void ComplexTask::Print() const
{
	std::cout << "---Complex Task---" << std::endl;
	std::cout << "Description: " << getDescription() << std::endl;
	std::cout << "Size: " << getSize() << std::endl;
	std::cout << "Progress: " << getProgress() * 100 << "%" << std::endl;
	std::cout << "Is it completed? ";
	(getIsComplete()) ? std::cout << " - yes" << std::endl : std::cout << " - no" << std::endl;
	std::cout << "Number of other tasks inside this one: " << tasks.size() << std::endl << std::endl;
}

ComplexTask * ComplexTask::clone() const
{
	return new ComplexTask(*this);
}

void ComplexTask::printTasks() const
{
	for (unsigned i = 0; i < tasks.size(); i++)
	{
		tasks[i]->Print();
		std::cout << std::endl;
	}
}
