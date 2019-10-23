#pragma once
#include "Person.h"
class Employee :
	public Person
{
public:
	Employee();
	Employee(double, std::string);
	void printname();
	~Employee();
private:
	double salary;
};

