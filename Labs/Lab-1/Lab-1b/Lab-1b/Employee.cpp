#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee() : Person()
{
	salary = 0;
}

Employee::Employee(double sal, string n) : Person(n)
{
	salary = sal;
}

void Employee::printname()
{
	cout << "\nName: " << name;
	cout << "\nSalary: " << salary;
}


Employee::~Employee()
{
}
