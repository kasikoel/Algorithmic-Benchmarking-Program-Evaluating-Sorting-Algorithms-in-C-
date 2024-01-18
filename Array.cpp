#include<iostream>
#include<ctime>
#include<chrono>
#include<vector>
#include"newSort2.h"
#include"FastSortAlgorithms.h" 
#include"Ssort.h"
using namespace std::chrono;
using namespace std;
const int CAPACITY = 1000;
// source: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ & https://cplusplus.com/forum/general/7784/ 
void printArray(int arr[]);
// Driver Program 
int main()
{
	srand(time(NULL));
	//create input array
	int arr[CAPACITY] = { 0 };
	int i = 0;
	int num = 0;
	char again = 'a';
	do
	{
		while (i < CAPACITY)
		{
			bool check;
			do
			{
				num = rand() % 1000 + 1;
				check = true;
				for (int j = 0; j < i; j++)
				{
					if (num == arr[j])
					{
						check = false;
						break;
					}
				}
			} while (!check);
			arr[i] = num;
			i++;
		}
		int arr2[CAPACITY] = { 0 };
		int arr3[CAPACITY] = { 0 };
		int arr4[CAPACITY] = { 0 };
		int arr5[CAPACITY] = { 0 };
		int arr6[CAPACITY] = { 0 };
		for (int i = 0; i < CAPACITY; i++)
		{
			arr2[i] = arr[i];
			arr3[i] = arr[i];
			arr4[i] = arr[i];
			arr5[i] = arr[i];
			arr6[i] = arr[i];
		}
		int choice = 0;
		int n = CAPACITY;
		char ans = 'a';
		do
		{
			cout << " What Sort would you like to choose: " << endl;
			cout << " 1: Bubble Sort" << endl
				<< " 2: Selection Sort" << endl
				<< " 3: Quick Sort" << endl
				<< " 4: Heap Sort" << endl
				<< " 5: Tim Sort" << endl;
			cout << " Enter digit (1-5): ";
			cin >> choice;
			if (choice < 1 || choice > 5)
				cout << " Invalid number entered! " << endl;

		} while (choice < 1 || choice > 5);
		switch (choice)
		{
		case 1:
		{
			do
			{
				cout << " Would you like to sort sorted data ( Y for Sorted or N for Unsorted ): ";
				cin >> ans;
				if ((ans != 'Y') && (ans != 'N'))
				{
					cout << " Invalid Answer (Y for sorted data or N for unsorted data)" << endl;
				}
			} while ((ans != 'Y') && (ans != 'N'));

			if (ans == 'Y')
			{
				bubbleSort(arr2, n);
				for (int j = 0; j < 5; j++)
				{
					cout << arr2[j] << ", ";
				}
			}
			auto start = high_resolution_clock::now();
			bubbleSort(arr2, n);
			auto stop = high_resolution_clock::now();
			// Subtract stop and start timepoints and
		// cast it to required unit. Predefined units
		// are nanoseconds, microseconds, milliseconds,
		// seconds, minutes, hours. Use duration_cast()
		// function.
			auto duration = duration_cast<microseconds>(stop - start);
			cout << " Time Taken by Bubble Sort:" << duration.count() << " Microseconds " << endl;
			for (int j = 0; j < 50; j++)
			{
				cout << arr2[j] << ", ";
			}
			break;
		}
		case 2:
		{
			do
			{
				cout << " Would you like to sort sorted data ( Y for Sorted or N for Unsorted ): ";
				cin >> ans;
				if ((ans != 'Y') && (ans != 'N'))
				{
					cout << " Invalid Answer (Y for sorted data or N for unsorted data)" << endl;
				}
			} while ((ans != 'Y') && (ans != 'N'));

			if (ans == 'Y')
			{
				selectionSort(arr3, n);
				for (int j = 0; j < 5; j++)
				{
					cout << arr3[j] << ", ";
				}
			}
			auto start = high_resolution_clock::now();
			selectionSort(arr3, n);
			auto stop = high_resolution_clock::now();
			// Subtract stop and start timepoints and
		// cast it to required unit. Predefined units
		// are nanoseconds, microseconds, milliseconds,
		// seconds, minutes, hours. Use duration_cast()
		// function.
			auto duration = duration_cast<microseconds>(stop - start);
			cout << " Time Taken by Selection Sort:" << duration.count() << " Microseconds " << endl;
			for (int j = 0; j < 50; j++)
			{
				cout << arr3[j] << ", ";
			}
			break;
		}
		case 3:
		{
			do
			{
				cout << " Would you like to sort sorted data ( Y for Sorted or N for Unsorted ): ";
				cin >> ans;
				if ((ans != 'Y') && (ans != 'N'))
				{
					cout << " Invalid Answer (Y for sorted data or N for unsorted data)" << endl;
				}
			} while ((ans != 'Y') && (ans != 'N'));

			if (ans == 'Y')
			{
				quickSort(arr4, 0, n - 1);
				for (int j = 0; j < 5; j++)
				{
					cout << arr4[j] << ", ";
				}
			}
			auto start = high_resolution_clock::now();
			quickSort(arr4, 0, n - 1);
			auto stop = high_resolution_clock::now();
			// Subtract stop and start timepoints and
		// cast it to required unit. Predefined units
		// are nanoseconds, microseconds, milliseconds,
		// seconds, minutes, hours. Use duration_cast()
		// function.
			auto duration = duration_cast<microseconds>(stop - start);
			cout << " Time Taken by Quick Sort:" << duration.count() << " Microseconds " << endl;
			for (int j = 0; j < 50; j++)
			{
				cout << arr4[j] << ", ";
			}
			break;
		}
		case 4:
		{
			do
			{
				cout << " Would you like to sort sorted data ( Y for Sorted or N for Unsorted ): ";
				cin >> ans;
				if ((ans != 'Y') && (ans != 'N'))
				{
					cout << " Invalid Answer (Y for sorted data or N for unsorted data)" << endl;
				}
			} while ((ans != 'Y') && (ans != 'N'));

			if (ans == 'Y')
			{
				heapSort(arr5, n);
				for (int j = 0; j < 5; j++)
				{
					cout << arr5[j] << ", ";
				}
			}
			auto start = high_resolution_clock::now();
			heapSort(arr5, n);
			auto stop = high_resolution_clock::now();
			// Subtract stop and start timepoints and
		// cast it to required unit. Predefined units
		// are nanoseconds, microseconds, milliseconds,
		// seconds, minutes, hours. Use duration_cast()
		// function.
			auto duration = duration_cast<microseconds>(stop - start);
			cout << " Time Taken by Heap Sort:" << duration.count() << " Microseconds " << endl;
			for (int j = 0; j < 50; j++)
			{
				cout << arr5[j] << ", ";
			}
			break;
		}
		case 5:
		{
			do
			{
				cout << " Would you like to sort sorted data ( Y for Sorted or N for Unsorted ): ";
				cin >> ans;
				if ((ans != 'Y') && (ans != 'N'))
				{
					cout << " Invalid Answer (Y for sorted data or N for unsorted data)" << endl;
				}
			} while ((ans != 'Y') && (ans != 'N'));

			if (ans == 'Y')
			{
				timSort(arr6, n);
				for (int j = 0; j < 5; j++)
				{
					cout << arr6[j] << ", ";
				}
			}
			auto start = high_resolution_clock::now();
			timSort(arr6, n);
			auto stop = high_resolution_clock::now();
			// Subtract stop and start timepoints and
		// cast it to required unit. Predefined units
		// are nanoseconds, microseconds, milliseconds,
		// seconds, minutes, hours. Use duration_cast()
		// function.
			auto duration = duration_cast<microseconds>(stop - start);
			cout << " Time Taken by Tim Sort:" << duration.count() << " Microseconds " << endl;
			for (int j = 0; j < 50; j++)
			{
				cout << arr6[j] << ", ";
			}
			break;
		}
		}
		cout << " \n Would you like to run the program again? ( Y for yes, N for no): ";
		cin >> again;
	} while ((again == 'Y') || (again == 'y'));
	return 0;
}