#include <iostream>
using namespace std;

// Complete this function to implement recursive binary search
int binarySearch(int arr[], int left, int right, int x) {
	// Your code here
	// make sure that the array is big 
	if (right >= left) {
		// calculate midpoint
		int middle = left + (right - left) / 2;

		// check if the value to search for IS the midpoint
		if (arr[middle] == x) {
			return middle;
		}

		// x is smaller than the middle search the first half of the array
		if (arr[middle] > x) {
			return binarySearch(arr, left, middle - 1, x); // THERE COULD BE AN ISSUE HERE
		}

		// search the second half of the array
		return binarySearch(arr, middle + 1, right, x);
	}

	// if x is not inside, return -1
	return -1;
}

int main() {
	// Example sorted array
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int result;

	// values to check
	int toCheck[] = { 2, 40, 10, 4, -2, 100 };
	int size = sizeof(toCheck) / sizeof(toCheck[0]);

	for (int i = 0; i < size; i++) {
		result = binarySearch(arr, 0, n - 1, toCheck[i]);
		if (result == -1) {
			cout << "Element not found in the array" << endl;
		}
		else {
			cout << "Element found at index: " << result << endl;
		}
	}

	return 0;
}