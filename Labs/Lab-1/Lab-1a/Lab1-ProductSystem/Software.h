#pragma once
#include "Product.h"

class Software : public Product
{
public:
	Software();
	Software(double);
	double getGrossPrice() const; // product has the method definition we want
	~Software();
};

