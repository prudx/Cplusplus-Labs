#pragma once
#include "Vehicle.hpp"

class Auto : public Vehicle
{
public:
	Auto(int, int);
	int getMomentum();
private:
	int speed;
};