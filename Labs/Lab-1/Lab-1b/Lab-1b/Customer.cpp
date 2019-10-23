#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;


Customer::Customer() : Person()
{
}

Customer::Customer(string n) : Person(n)
{
}

void Customer::printname()
{
	cout << "\nName: " << name;
	cout << "\nCustomer would like to make a complaint.\n\n";
}


Customer::~Customer()
{
}
