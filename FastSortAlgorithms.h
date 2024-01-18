#pragma once
//Hunter Tamburo
//Fast Sort Algorithms

#ifndef FastSortAlgorithms
#define FastSortAlgorithms
//#include <iostream>
//using namespace std;

//const int CAPACITY = 1500;

//class FastSortArray
//{//
//public:
	//FastSortArray(); don't need a construtor
	void heapify(int array[], int sizearray, int node);
	void heapSort(int array[], int sizearray); //reverse array
	int partition(int array[], int start, int end);
	void swap(int arr[], int i, int j);
	void quickSort(int array[], int start, int end);


//};
#endif


