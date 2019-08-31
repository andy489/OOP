#pragma once
#include "Task.h"
class SimpleTask :public Task
{
public:
	SimpleTask();
	SimpleTask(std::string description);

	const double Work(const double workSize) override;
	void Print() const override;
	SimpleTask* clone() const override;
};
