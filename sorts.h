/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8, Part 1
   PROGRAMMER: Patrick Schlapp
   LOGON ID:   z1806407
   DUE DATE:   11/17/2016

   FUNCTION:   This program builds and prints lists.
*********************************************************************/

#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);

template <class T> //This builds the list of items defined in the external file
void buildList(vector<T>& set, const char* fileName){
	T item;
	ifstream input;
	input.open(fileName);
	if (input.is_open()){
		input >> item;
			while (!input.eof()){
				set.push_back(item);
				input >> item;
			}
	}
	input.close();
}
template <class T> //This function outputs the contents of the designated set
void printList(const vector<T>& set, int itemWidth, int numPerLine){
	int count = 1;
	for (size_t i = 0; i < set.size(); i++){
		cout << setw(itemWidth) << set[i] << " ";
		if (count == numPerLine){
			cout << endl;
			count = 0;
		}
		count++;
	}
	cout << endl;
}
template <class T> //Simple boolean to see if item1<item2 for use in quicksorting
bool lessThan(const T& item1, const T& item2){
	return (item1 < item2);
}
template <class T> //Simple boolean to see if item1>item2 for use in quicksorting
bool greaterThan(const T& item1, const T& item2){
	return (item1 > item2);
}
#endif
