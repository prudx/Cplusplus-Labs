#pragma once
#include "Auto.hpp"

class Truck : public Auto
{
	public:
		Truck();
		Truck(int, int, int);
		int getWeight() const;
	private:
		int trailerWeight;
};