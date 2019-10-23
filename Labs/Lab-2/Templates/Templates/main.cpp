#include <iostream>;
using namespace std;
//x00127907 Daniel Maguire

/*=========Q1==========*/
template<typename T>
void SwapByReference(T &lhs, T &rhs);

template<typename T>
void SwapByPointer(T *lhs, T *rhs);

/*=========Q2==========*/
template<typename WhatKind>
void multiples(WhatKind &sum, WhatKind x, int n);

/*=========Q3===========*/
template<typename T1, typename T2>
T1 init(T1 num1, T1 num2, T2 start);

/*=========Q4===========*/
template<typename T> T * quicksort(T *array, int start, int end);
template<typename T> int partition(T* array, int start, int end);




int main(){
	/*=========Q1==========*/
	cout << "Question 1" << endl;
	int a = 1;
	int b = 2;

	/*cout << "enter two integers to be swapped:\n";
	cin >> a;
	cin >> b;*/

	cout << "Value a: " << a << "\tValue b: " << b << endl;

	cout << "Swapping by reference..." << endl;
	SwapByReference(a, b);

	cout << "Value a: " << a << "\tValue b: " << b << endl;

	int *c = new int(3);
	int *d = new int(4);
	
	cout << "\nValue c: " << c << "\tValue d: " << d << endl;
	cout << "Swapping by pointer..." << endl;
	SwapByPointer(c, d);

	cout << "Value c: " << c << "\tValue d: " << d << endl;

	/*=========Q2==========*/
	cout << "\nQuestion 2" << endl;
	int sum = 0;
	multiples(sum, 1, 3);
	cout << sum << endl;

	sum = 0;
	multiples(sum, 2, 3);
	cout << sum << endl;
	cout << endl;
	

	/*=========Q3==========*/
	cout << "Question 3" << endl;
	double start = 2.2;
	cout << init(2, 3, start) << endl;


	/*=========Q4==========*/
	cout << "\nQuestion 4" << endl;
	const int SIZE = 10;
	int array[SIZE] = { 3,2,4,5,1,7,6,8,10,9 };

	cout << "Pre sort" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;

	quicksort(array, 0, 9);
	cout << "Sorted" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}


	cout << "\n\n\n";
	system("pause");
	return 0;
}






/*=========Q1==========*/
template <typename T> void SwapByReference(T &lhs, T &rhs) {
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T> void SwapByPointer(T *lhs, T *rhs) {
	T *temp = lhs;
	lhs = rhs;
	rhs = temp;
}

/*=========Q2==========*/
template<typename WhatKind> void multiples(WhatKind &sum, WhatKind x, int n) {
	for (int i = 0; i < n; i++) {
		sum += (i + 1)*x;
	}
};

/*============Q3==============*/
template<typename T1, typename T2>
T1 init(T1 num1, T1 num2, T2 start)
{
	start = 1;

	return num1 + num2;;
}

/*============Q4==============*/
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