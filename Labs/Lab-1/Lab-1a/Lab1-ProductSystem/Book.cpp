#include "Book.h"

Book::Book()
{
	netPrice = 0;
}

Book::Book(double netP) : Product(netP)
{
}

double Book :: getGrossPrice() const{
	return netPrice;
}

Book::~Book()
{
}
