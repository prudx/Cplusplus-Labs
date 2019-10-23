#include <iostream>
using namespace std;

template<typename T>
void merge(T *arr, int begin, int end)
{
	T mid = (begin + end) / 2;

	int i = begin;
	T j = mid + 1;
	int k = i;

	int temp[100];

	//while there is data to compare, keep looking and check which value is lower and add it to the temp
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	//flushing rest of data into it
	//flushing first block - to end of first block (mid)
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	//flushing 2nd block - to end of 2nd block ( e )
	while (j <= end) {
		temp[k++] = arr[j++];
	}

	//transfering temp data to pointer
	for (int i = begin; i <= end; i++) {
		arr[i] = temp[i];
	}
}

template<typename T>
void mergeSort(T arr[], int begin, int end){

	//check if data is solo
	if (begin >= end) {
		return;
	}

	//if not lets find the middle
	int mid = (begin + end) / 2;

	//recursively call mergeSort to keep splitting blocks until it can start <= end
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);

	//merge
	merge(arr, begin, end);
}

int main() {

	cout << "How many numbers will you enter?";
	int n = 0;
	cin >> n; 

	int arr[100]; // can't let n be the size of the array due to arrays being made at compile time

	for (int i = 0; i < n; i++) {
		cout << "Please enter number for: "<< i + 1 << endl;
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}

	system("pause");
}