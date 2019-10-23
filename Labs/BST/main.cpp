#include <iostream>
using namespace std;

//Q1
template <typename T> void swapByRef(T &lhs, T &rhs);// swap by reference function
template <typename T> void swapByAdd(T *lhs, T *rhs);// swap by address function

//Q2
template <typename WhatKind> void multiples(WhatKind &sum, WhatKind x, int n);// multples

//Q3
template <typename T1,typename T2>T1 init(T1 num1, T1 num2, T2 start);

//Q4
template <typename T>T* quicksort(T* array, int start, int end); // quicksort template function
template<typename T> int partition(T* array, int start, int end);
int main() {

	//Q1
	cout << "Question 1" << endl;
	float a = 2.2, b = 6.3;
	int x = 5, y = 9;

	cout << "Before swap by reference" << endl;
	cout << a << " " << b << endl;
	cout << x << " " << y << endl;

	swapByRef(a, b);
	swapByRef(x, y);

	cout << endl;
	cout << "After swap by reference" << endl;	
	cout << a << " " << b << endl;
	cout << x << " " << y << endl;

	int *i = new int(5);
	int *j = new int(9);
	float *p = new float(3.3);
	float *q = new float(4.5);

	cout << endl;
	cout << "Before swap by address" << endl;
	cout << i << " " << j << endl;
	cout << p << " " << q << endl;

	swapByAdd(i, j);
	swapByAdd(p, q);

	cout << endl;
	cout << "After swap by address" << endl;
	cout << i << " " << j << endl;
	cout << p << " " << q << endl;
	
	cout << endl;

	//Q2
	cout << "Question 2" << endl;
	int sum = 0;
	multiples(sum, 1, 3);
	cout << sum << endl;

	sum = 0;
	multiples(sum, 2, 3);
	cout << sum << endl;
	cout << endl;

	//Q3
	cout << "Question 3" << endl;
	double start = 2.2;
	cout << init(2, 3, start) << endl;

	//Q4
	cout << "Question 4" << endl;
	const int SIZE = 10;
	int array[SIZE] = { 3,2,4,5,1,7,6,8,10,9 };

	cout << "*** Before Sort ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;

	quicksort(array, 0, 9);
	cout << "Sorted" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}

	cout << endl;

	system("pause");
}

//Q1
template <typename T> void swapByRef(T &lhs, T &rhs) {
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T> void swapByAdd(T *lhs, T *rhs) {
	T *temp = lhs;
	lhs = rhs;
	rhs = temp;
}

//Q2
template<typename WhatKind> void multiples(WhatKind &sum, WhatKind x, int n)
{
	sum += 1;
	for (int i = 0; i < n; i++) {
		sum += ((i + 1) *x);
	}
}

//Q3
template<typename T1, typename T2>
T1 init(T1 num1, T1 num2, T2 start)
{
	start = 1;
	
	return num1 + num2;;
}

//Q4
template<typename T> T * quicksort(T *array, int start, int end)
{
	if (start < end) {
		int p = partition(array, start, end);
		quicksort(array, start, p - 1);
		quicksort(array, p + 1, end);

	}
	return array;
}

//http://technotip.org/forums/topic/c-program-to-create-a-template-function-for-quick-sort 
template<typename T> int partition(T* array, int start, int end) {
	T num = array[start];
	int i = start + 1;
	int j = end;
	T temp;

	while (1) {
		while (i < end && num > array[i])
			i++;
		while (num < array[j])
			j--;
		if (i < j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else {
			temp = array[start];
			array[start] = array[j];
			array[j] = temp;
			return (j);
		}
	}

}
