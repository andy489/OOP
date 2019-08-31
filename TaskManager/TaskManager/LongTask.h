#pragma once
#include "Task.h"

class LongTask : public Task
{
public:
	LongTask();
	LongTask(std::string description);
	
	const double Work(const double workSize) override;
	void Print() const override;
	LongTask* clone() const override;
};
