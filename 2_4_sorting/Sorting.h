#pragma once

template<class Elem, class Comp>
class Sorting
{
private:
	void swap(Elem A[], int, int);
	int findpivot(Elem A[], int i, int j); // for quick sort
	int partition(Elem A[], int l, int r, Elem& pivot); // for quick sort

public:
	void bubsort(Elem A[], int n); // bubble sort
	void selsort(Elem A[], int n); // selection sort
	void inssort(Elem A[], int n); // insertion sort
	void inssort2(Elem A[], int n, int incr);  // modified version of insertion sort
	void shellsort(Elem A[], int n); // shell sort
	void qsort(Elem A[], int i, int j); // quick sort
	void mergesort(Elem A[], Elem temp[], int left, int right); // Merge Sort
	void mergesort_opt(Elem A[], Elem temp[], int left, int right); // Merge Sort(optimization): Use insertion sort to sort small sublists
	void heapsort(Elem A[], int n); // Heap Sort
	void binsort(Elem A[], int n); // bin sort
	void radix(Elem A[], Elem B[], int n, int k, int r, int cnt[]); //radix sort
};
