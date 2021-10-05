#pragma once
#include<iostream>
using namespace std;

template <class Elem,class Comp>
class maxheap
{
private:
	Elem* Heap; // pointer to the heap array // ��ά���飬�б�ʾÿ�����ݣ��б�ʾ�����ݵĹ�ϵ��Heap[pos][0]=parent;Heap[pos][1]=leftchild;Heap[pos][2]=rightchild;Heap[pos][3]=leftsibling;Heap[pos][4]=rightsibling.
	int size;  // maximun size of the heap
	int n;  // number of elems now in heap
	void siftdown(int);  // put element in place

public:
	maxheap(Elem* h, int num, int max) {
		size = max; // maximun size of the heap
		n = num; // number of elems now in heap -- length of h
		Heap = h; // Ϊʲô����newһ����ά���飿
		buildHeap();
	}

	int heapsize()const;
	bool isLeaf(int pos)const;
	int leftchild(int pos)const;
	int rightchild(int pos)const;
	int parent(int pos)const;
	bool insert(const Elem&);
	bool removemax(Elem&);
	bool remove(int, Elem&);
	void buildHeap();
};

