#pragma once
#include<iostream>
using namespace std;

#define ROOT NULL //?
#define defineMaxSize 20

// parent pointer implementation
class GentreePPI // general tree for UNION/FIND //Ӧ�ó������Ա���ͬor��ͬ
{
private:
	int* array; // node array // array��һά���飬������index��Ӧ��parent����index
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

