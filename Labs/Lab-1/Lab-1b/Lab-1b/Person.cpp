#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person()
{
	name = "blank";
}

Person::Person(string s)
{
	name = s;
}


void Person::printname()
{
	cout << "\nName: " << name;
}

Person::~Person()
{
}
