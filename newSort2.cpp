// C++ program to perform TimSort.
#include"newSort2.h"
#include<algorithm>
using namespace std;
const int RUN = 32;
// Source: https://www.geeksforgeeks.org/sorting-algorithms/ & https://www.geeksforgeeks.org/tree-sort/ 
// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}


	// Merges two subarrays of array[].
	// First subarray is arr[begin..mid]
	// Second subarray is arr[mid+1..end]
	void merge(int array[], int const left, int const mid,
		int const right)
	{
		auto const subArrayOne = mid - left + 1;
		auto const subArrayTwo = right - mid;

		// Create temp arrays
		auto* leftArray = new int[subArrayOne],
			* rightArray = new int[subArrayTwo];

		// Copy data to temp arrays leftArray[] and rightArray[]
		for (auto i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];
		for (auto j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];

		auto indexOfSubArrayOne
			= 0, // Initial index of first sub-array
			indexOfSubArrayTwo
			= 0; // Initial index of second sub-array
		int indexOfMergedArray
			= left; // Initial index of merged array

		// Merge the temp arrays back into array[left..right]
		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				array[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				array[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// left[], if there are any
		while (indexOfSubArrayOne < subArrayOne) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// right[], if there are any
		while (indexOfSubArrayTwo < subArrayTwo) {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n)
{

	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min((i + RUN - 1),
			(n - 1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n;
		size = 2 * size)
	{

		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n;
			left += 2 * size)
		{

			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1),
				(n - 1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}
