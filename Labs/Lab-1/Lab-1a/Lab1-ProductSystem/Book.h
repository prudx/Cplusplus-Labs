#pragma once
#include "Product.h"

class Book : public Product
{
public:
	Book();
	Book(double);
	double getGrossPrice() const; //this uses the product class method
	~Book();
};



