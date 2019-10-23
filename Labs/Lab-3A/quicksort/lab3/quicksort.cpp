#include<iostream>
#include<utility>
template<typename T> void quickSort(T *arr, int begin, int end);
template<typename T> int partition(T *arr, int begin, int end);
template<typename T> void printArray(T arr[], int size);

template<typename T> 
void quickSort(T *arr, int begin, int end)
{
	if (begin < end) {
		int p = partition(arr, begin, end); //partition index
		quickSort(arr, begin, p - 1);
		quickSort(arr, p + 1, end);
	}
	else {
		//failsafe 
		return;
	}
}
 
template<typename T> 
int partition(T* arr, int begin, int end) 
{
	T pivot = arr[end];
	int i = begin;

	for (int j = begin; j < end; j++) {
		if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[end], arr[i]);
	return i;
}

//print array template function, to debloat main
template<typename T> 
void printArray(T arr[], int size) {
	for (int i = 0; i < size; i++) std::cout<< arr[i] << " ";
	printf("\n\n");
}

int main() 
{
	int const size = 10;

	int numbers[size] = { 2,1,3,6,10,9,8,7,4,5 }; //{ 3,4,2,1,6,5,7,8,9,10 };

	std::cout << "Unsorted: " << std::endl;
	printArray(numbers, size);
	quickSort(numbers, 0, size-1);	//perform sort
	std::cout << "Sorted: " << std::endl;
	printArray(numbers, size);

	
	double numbersDouble[size] = { 2.2,1.1,3.3,6.6,5.5,4.4,8.8,7.7,10.0,9.9 };

	std::cout << "Unsorted: " << std::endl;
	printArray(numbersDouble, size);
	quickSort(numbersDouble, 0, size - 1); //perform sort
	std::cout << "Sorted: " << std::endl;
	printArray(numbersDouble, size);
	

	system("pause");
	return 0;
}