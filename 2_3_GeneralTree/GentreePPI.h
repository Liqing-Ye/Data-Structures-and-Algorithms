#pragma once
#include<iostream>
using namespace std;

#define ROOT NULL //?
#define defineMaxSize 20

// parent pointer implementation
class GentreePPI // general tree for UNION/FIND //应用场景：对比相同or不同
{
private:
	int* array; // node array // array是一维数组，储存着index对应的parent结点的index
	int size; // size of node array
	int FIND(int) const; // find root

public:
	GentreePPI(int sz = defineMaxSize) {
		size = sz;
		array = new int[size];
	}
	~GentreePPI() {
		delete[]array;
	}

	void UNION(int, int); // merge equivalences
	bool differ(int, int); // TRUE if not in same tree
};

