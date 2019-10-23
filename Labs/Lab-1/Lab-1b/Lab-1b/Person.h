#pragma once
#include <string>

class Person {
public: 
	Person();
	Person(std::string); // initialise the name 
	virtual void printname(); //= 0; //can't be instaciated when person is made pure virtual method (abstract class)
	~Person();
protected: 
	std::string name; };

