/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8, Part 3
   PROGRAMMER: Patrick Schlapp
   LOGON ID:   z1806407
   DUE DATE:   11/17/2016
 
   FUNCTION:   This handles the recursive mergesort
*********************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
using namespace std;

template <class T> void mergeSort(vector<T>&, bool(*)(const T&, const T&));
template <class T> void mergeSort(vector<T>&, int, int, bool(*)(const T&, const T&));
template <class T> void merge(vector<T>&, int, int, int, bool(*)(const T&, const T&));

template <class T> //This is the initial mergesort call, which allows for further recursive calling
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	mergeSort(set, 0, set.size() - 1, compare);
}
template <class T> //This is the mergesort call that does all the real work
void mergeSort(vector<T>& set, int low, int high, bool(*compare)(const T&, const T&)){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid + 1, high, compare);
		merge(set, low, mid, high, compare);
	}
}
template <class T> //This handles the merging of the two sections that are being compared to each other
void merge(vector<T>& set, int low, int mid, int high, bool(*compare)(const T&, const T&)){
	vector<T> temp(high - low + 1);
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high){
		if (compare(set[j], set[i])){
			temp[k] = set[j];
			j++;
			k++;
		}else{
			temp[k] = set[i];
			i++;
			k++;
		}
	}
	while (i <= mid){
		temp[k] = set[i];
		i++;
		k++;
	}
	while (j <= high){
		temp[k] = set[j];
		j++;
		k++;
	}
	for (i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i];
}
#endif
