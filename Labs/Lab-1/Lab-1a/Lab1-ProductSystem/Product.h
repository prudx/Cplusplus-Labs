#pragma once

class Product
{
public:
	Product();
	Product(double);
	virtual ~Product();
	virtual double getGrossPrice() const;
	//double getNetPrice();
protected:
	//void setNetPrice(double in);
	double netPrice;
};

