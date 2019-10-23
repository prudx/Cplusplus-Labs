#include "Software.h"

Software::Software() 
{
	netPrice = 0;
}

Software::Software(double netP) : Product (netP)
{
}

double Software :: getGrossPrice() const {
	return netPrice * 1.21;
}

Software::~Software()
{
}
