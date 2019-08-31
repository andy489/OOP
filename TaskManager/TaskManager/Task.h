#pragma once
#include <iostream>
#include <string>

class Task
{
private:
	std::string description;
	int size;
	double progress;
	bool isComplete=false;
protected:
	void setIsComplete();
public:
	Task();
	Task(std::string description);

	const std::string getDescription() const;
	const int getSize() const;
	const double getProgress() const;
	const bool getIsComplete() const;

	void setDescription(const std::string description);
	void setSize(const int size);
	void setProgress(const double progress);

	virtual const double Work(const double workSize) = 0;
	virtual void Print() const = 0;
	virtual Task* clone() const = 0;
};
