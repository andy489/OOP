#include "Task.h"

void Task::setIsComplete()
{
	this->isComplete = true;
}

Task::Task()
{
	setDescription("");
	setSize(0);
	setProgress(0);
}

Task::Task(std::string description):Task()
{
	this->description = description;
}

const std::string Task::getDescription() const
{
	return this->description;
}

const int Task::getSize() const
{
	return this->size;
}

const double Task::getProgress() const
{
	return this->progress;
}

const bool Task::getIsComplete() const
{
	return this->isComplete;
}

void Task::setDescription(const std::string description)
{
	this->description = description;
}

void Task::setSize(const int size)
{
	this->size = size;
}

void Task::setProgress(const double progress)
{
	this->progress = progress;
}
