#pragma once
#include "Person.h"
#include <string>

class Customer :
	public Person
{
public:
	Customer();
	Customer(std::string);
	void printname();
	~Customer();
};

