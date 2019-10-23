#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#include "Product.h" //not required as book.h and software.h include product.h
#include "Book.h"
#include "Software.h"
//#include <conio>
using namespace std;


//Daniel Maguire - x00127907





int main() {

	double price;
	Product *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

	vector<Product*> products(8);
	//products.push_back(p1);
	//products.push_back(p2);

	
	cout << "Please enter the price of the Software: ";
	cin >> price;
	products[0] = new Software(price);
	

	cout << "Please enter the price of the Book: ";
	cin >> price;
	products[1] = new Book(price);

	cout << "\nThe price of the software: ";
	cout << products[0]->getGrossPrice() << "\n";
	cout << "The price of the book: ";
	cout << products[1]->getGrossPrice() << "\n";

	cout << "Please fill the remaining 6 products: ";
	for (int i = 2; i < products.capacity(); ++i) 
	{
		string input;
		double price;

		cout << "\nEnter the price of the product: ";
		cin >> price;
		cout << "Is the product a book or software: ";
		cin >> input;
		cout << "Thank you, " + input + " added to vector\n";

		if (input == "book") {
			products[i] = new Book(price);

		} else if (input == "software") {
			products[i] = new Software(price);
		}
		else {
			cout << "error with input";
		};
	};

	
	for (int i = 0; i < products.capacity(); ++i)
	{
		cout << "\n" << products[i]->getGrossPrice();
	};

	cout << "\nNow we will sort by gross price: \n";
	std::sort(products.begin(), products.begin());
	
	for (int i = 0; i < products.capacity(); ++i)
	{
		cout << "\n" << products[i]->getGrossPrice();
	};


	system("pause");
	return 0;
}
