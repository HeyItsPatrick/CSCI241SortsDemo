/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8, Part 2
   PROGRAMMER: Patrick Schlapp
   LOGON ID:   z1806407
   DUE DATE:   11/17/2016
 
   FUNCTION:   This handles the recursive quicksort
*********************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
using namespace std;

template <class T> void quickSort(vector<T>&, bool(*)(const T&, const T&));
template <class T> void quickSort(vector<T>&, int, int, bool(*)(const T&, const T&));
template <class T> int partition(vector<T>&, int, int, bool(*)(const T&, const T&));

template <class T> //This is the initial quicksort call, which allows for further recursive calling
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	quickSort(set, 0, set.size() - 1, (compare));
}
template <class T> //This is the quicksort call that does all the real work
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&)){
	int pivot;
	if (start < end){
		pivot = partition(set, start, end, compare);
		quickSort(set, start, pivot - 1, compare);
		quickSort(set, pivot + 1, end, compare);
	}
}
template <class T> //Thie sets the partion the quicksort methods are pivoting around
int partition(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&)){
	int pivotIndex, mid;
	T pivotValue;
	mid = (start + end) / 2;
	T a;
	a = set[mid];
	set[mid] = set[start];
	set[start] = a;

	pivotIndex = start;
	pivotValue = set[start];
	for (int scan = start + 1; scan <= end; scan++){
		if (compare(set[scan], pivotValue)){
			pivotIndex++;

			a = set[pivotIndex];
			set[pivotIndex] = set[scan];
			set[scan] = a;
		}
	}
	a = set[pivotIndex];
	set[pivotIndex] = set[start];
	set[start] = a;
	return pivotIndex;
}
#endif
