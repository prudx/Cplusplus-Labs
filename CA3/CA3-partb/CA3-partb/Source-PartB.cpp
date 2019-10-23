//Daniel maguire - x00127907
//identify O(nlogm) solution to find smallest (in value) m integer numbers

/*
I choose to use quickSort algorithm, as it has an average case time complexity
of O(nlogn) provided a pivot is chosen wisely. So is a suitable candidate for 
Part B of CA3

I will process it using an integer implementation of quickSort, as there is no need
to make it a templated version (since we are only dealing with integers). I will 
store the m numbers in a standard array of integers. I will implement it all in this
source file, as proper object oreintation does not seem to be of concern for this 
question
*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int unsorted[] = { 2,5,6,3,4,1 };
	int sorted;

	//using algorithms library
	qsort(unsorted, 5, INT16_MAX, 0);	//throws error


	for (int i = 0; i < 6; i++) {
		cout << unsorted[i] << endl;
	}

	system("pause");
	return 0;
}