#pragma once

class Vehicle
{
	public:
		Vehicle();
		int getWeight() const;
		void setWeight(int);
	private:
		int weight;
};