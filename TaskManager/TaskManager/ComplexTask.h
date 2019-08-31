#pragma once
#include <vector>
#include "Task.h"

class ComplexTask : public Task
{
private:

	std::vector<Task*> tasks;

public:

	ComplexTask();
	~ComplexTask();

	ComplexTask(const ComplexTask& c);
	ComplexTask& operator=(const ComplexTask& c);

	void addTask(Task* task);
	void removeTask(const int index);

	const double Work(const double workSize) override;
	void Print() const override;
	ComplexTask* clone() const override;

	void printTasks() const;

};
