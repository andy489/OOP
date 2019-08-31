#include "LongTask.h"

LongTask::LongTask() : Task()
{
	setSize(2);
}

LongTask::LongTask(std::string description):Task(description)
{
	setSize(2);
}

const double LongTask::Work(const double workSize)
{
	if (getIsComplete())
	{
		return workSize;
	}
	else
	{
		double currSize = getSize()*(1 - getProgress());
		if (currSize >= workSize)
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

void LongTask::Print() const
{
	std::cout << "---Long Task---" << std::endl;
	std::cout << "Description: " << getDescription() << std::endl;
	std::cout << "Size: " << getSize() << std::endl;
	std::cout << "Progress: " << getProgress() * 100 << "%" << std::endl;
	std::cout << "Is it completed? ";
	(getIsComplete()) ? std::cout << " - yes"  : std::cout << " - no" ;
	std::cout << std::endl<< std::endl;
}

LongTask * LongTask::clone() const
{
	return new LongTask(*this);
}
