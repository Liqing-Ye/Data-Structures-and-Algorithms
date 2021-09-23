#pragma once
#include"List.h"
#include<iostream>
using namespace std;

#define DefaultListSize 20

template <class Elem> 
class ArrayList : public List <Elem> // Array-based list
{
private:
	int maxSize; // Maximum size of list
	int listSize; // Actual elem count
	int fence; // Position of fence
	Elem* listArray; // Array holding list
public:
	ArrayList(int size = DefaultListSize) {
		maxSize = size;
		listSize = fence = 0;
		listArray = new Elem[maxSize]; //the array whose elements'  datatype is Elem
	}

	~ArrayList() {
		delete[]listArray;
	}

	void clear() {
		delete[]listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}

	bool insert(const Elem& item) {
		if (listSize >= maxSize)
			return false;
		for (int i = listSize; i > fence; i--)
			listArray[i] = listArray[i - 1];
		listArray[fence] = item; // insert element in the position of fence
		listSize++;
		return true;
	}

	bool append(const Elem& item) {
		if (listSize >= maxSize)
			return false;
		listArray[listSize++] = item;
		return true;
	}

	bool remove(Elem& item) {
		if (rightLength() == 0)
			return false;
		item = listArray[fence];
		for (int i = fence; i < listSize - 1; i++)
			listArray[i] = listArray[i + 1]; //move left to overwrite deleted data
		listSize--;
		return true;
	}

	void setStart() {
		fence = 0;
	}

	void setEnd() {
		fence = listSize;
	}

	void prev() {
		if (fence > 0)
			fence--;
	}

	void next() {
		if (fence < listSize)
			fence++;
	}

	int leftLength()const {
		return fence; //left side of the position of fence 
	}

	int rightLength()const {
		return listSize - fence; //right side of the position of fence, including the position of 'liseSize' 
	}

	bool setPos(int pos) {
		if (pos >= 0 && pos <= listSize)
			fence = pos; // can be set between 0 and 'listSize'
		return pos >= 0 && pos <= listSize;
	}

	bool getValue(Elem& item)const {
		if (rightLength() == 0)
			return false; // there is no number in the position of 'listSize'
		item = listArray[fence];
		return true;
	}
	
	void print()const {
		cout << "<";
		int i = 0;
		while (i < fence - 1)
			cout << listArray[i++] << ',';
		cout << listArray[i++] << '|';
		while (i < listSize - 1)
			cout << listArray[i++] << ',';
		cout << listArray[i] << '>' << endl;
	}

	//void print()const;
};

/*
template <class Elem>
void ArrayList<Elem>::print()const {
	cout << "<";
	int i = 0;
	while (i < fence - 1)
		cout << listArray[i++] << ',';
	cout << listArray[i++] << '|';
	while (i < listSize - 1)
		cout << listArray[i++] << ',';
	cout << listArray[i] << '>' << endl;
}
*/