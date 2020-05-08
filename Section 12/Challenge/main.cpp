// ArrayMultiplier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Used prototypes to keep main implementation at top
// All constant since the original data isn't going to change
int *applyAll(const int *const arr1, const size_t arr1_size, const int *const arr2, const size_t arr2_size);
void display(const int *const arr, const size_t arr_size);
size_t getArraySize(const int *const arr1);			// Gets array size only, if an limiter with value '-1' is at end of array

int main()
{

	int arr1[]{ 4, 2, 7, 2, 12, 15, 1, -1 };
	int arr2[]{ 10, 25, 50, 100, -1 };

	size_t arr1_size{ getArraySize(arr1) };
	size_t arr2_size{ getArraySize(arr2) };

	display(arr1, arr1_size);
	display(arr2, arr2_size);

	int *dynamic_ptr{ nullptr };
	dynamic_ptr = applyAll(arr1, arr1_size, arr2, arr2_size);

	display(dynamic_ptr, (arr1_size * arr2_size));
	delete[] dynamic_ptr;

	return 0;

}

int *applyAll(const int *const arr1, const size_t arr1_size, const int *const arr2, const size_t arr2_size) {

	int *arr_result{ nullptr };

	arr_result = new int[arr1_size * arr2_size];

	int index{};
	for (int i{ 0 }; i < arr1_size; i++) {
		for (int j{ 0 }; j < arr2_size; j++) {
			*(arr_result + (index + j)) = arr1[i] * arr2[j];
		}
		index += arr2_size;
	}

	return arr_result;

}

void display(const int *const arr, const size_t arr_size) {

	for (int i{ 0 }; i < arr_size; i++)
		cout << *(arr + i) << " ";
	cout << endl;

}

size_t getArraySize(const int *const arr) {

	size_t index{0};

	while (arr[index] != -1) {
		index++;

		if (index >= 500)
			return 0;	// For cases when there's (probably) no limiter, the loop terminates at index 500
	}

	return index;	// Since the limiter is to be excluded, index isn't incremented ( index != size )

}
