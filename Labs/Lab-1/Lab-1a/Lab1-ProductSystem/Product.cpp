#include "Product.h"


Product::Product()
{
	netPrice = 0;
}

Product::Product(double netP)
{
	netPrice = netP;
}

double Product::getGrossPrice() const{
	return 0;
}

Product::~Product()
{
}

//double Product::getNetPrice() {
//	return netPrice;
//}
//
//void Product::setNetPrice(double in) {
//	netPrice = in;
//}