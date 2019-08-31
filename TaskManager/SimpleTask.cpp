#include "SimpleTask.h"

SimpleTask::SimpleTask() : Task()
{
	setSize(1);
}

SimpleTask::SimpleTask(std::string description):Task(description)
{
	setSize(1);
}


const double SimpleTask::Work(const double workSize)
{
	if (getIsComplete())
	{
		return workSize;
	}
	else
	{		
		double currSize = getSize()*(1 - getProgress());
		if (currSize>= workSize)
		{
			setProgress(getProgress()+workSize/getSize());
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

void SimpleTask::Print() const
{
	std::cout << "---Simple Task---" << std::endl;
	std::cout << "Description: " << getDescription() << std::endl;
	std::cout << "Size: " << getSize() << std::endl;
	std::cout << "Progress: " << getProgress() * 100 << "%" << std::endl;
	std::cout << "Is it completed?";
	(getIsComplete()) ? std::cout << " - yes" : std::cout << " - no";
	std::cout << std::endl<< std::endl;
}

SimpleTask * SimpleTask::clone() const
{
	return new SimpleTask(*this);
}

