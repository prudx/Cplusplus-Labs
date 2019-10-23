#include <iostream>
//#include <vector>
//#include <algorithm>
#include <string>
#include "Customer.h"
#include "Employee.h"
//#include <conio>
using namespace std;


//Daniel Maguire - x00127907


int main() {
	Person *personPtr;

	personPtr = new Person("Daniel");
	personPtr->printname();
	//can't be instaciated when person is made pure virtual method (abstract class)

	cout << "\n";

	personPtr = new Employee(120000, "Daniel");
	personPtr->printname();

	cout << "\n";

	personPtr = new Customer("Daniel");
	personPtr->printname();
	

	system("pause");
	return 0;
}