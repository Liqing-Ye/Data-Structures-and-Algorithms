#include "Sorting.h"

template<class Elem, class Comp>
void Sorting<Elem, Comp>::swap(Elem A[], int i, int j) {
	int temp = A[j];
	A[j] = A[i];
	A[i] = temp;
}

template<class Elem,class Comp>
void Sorting<Elem, Comp>::bubsort(Elem A[], int n) { 
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (Comp::lt(A[j], A[j - 1]))
				swap(A, j, j - 1);
}

template<class Elem, class Comp>
void Sorting<Elem, Comp>::selsort(Elem A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int lowindex = i;
		for (int j = n - 1; j > i; j--)
			if (Comp::lt(A[j], A[lowindex])) // find the smaller value
				lowindex = j;
		if(lowindex!=i) // index check
			swap(A, i, lowindex);
	}
}

template<class Elem, class Comp>
void Sorting<Elem, Comp>::inssort(Elem A[], int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; (j > 0) && (Comp::lt(A[j], A[j - 1])); j--) // 逐渐增加一个数据扩大排序数组
			swap(A, j, j - 1);
}

template<class Elem, class Comp>
void Sorting<Elem, Comp>::inssort2(Elem A[], int n, int incr) {
	for (int i = incr; i < n; i += incr)
		for (int j = i;(j >= incr) && (Comp::lt(A[j], A[j - incr]));j -= incr)
			swap(A, j, j - incr);
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::shellsort(Elem A[], int n) { // Shellsort
	for (int i = n / 2; i > 2; i /= 2) // For each incr
		for (int j = 0; j < i; j++) // Sort sublists
			inssort2<Elem, Comp>(&A[j], n - j, i);
	inssort2<Elem, Comp>(A, n, 1);
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::qsort(Elem A[], int i, int j) { // Quicksort
	if (j <= i) return; // Don't sort 0 or 1 Elem 
	int pivotindex = findpivot(A, i, j);
	swap(A, pivotindex, j); // Put pivot at end 
	// k will be the first position in the right subarray
	int k = partition(A, i - 1, j, A[j]);
	swap(A, k, j); // Put pivot in place
	qsort<Elem, Comp>(A, i, k - 1);
	qsort<Elem, Comp>(A, k + 1, j);
}

template <class Elem, class Comp>
int Sorting<Elem, Comp>::findpivot(Elem A[], int i, int j){
	return (i + j) / 2;
}

template <class Elem, class Comp>
int Sorting<Elem, Comp>::partition(Elem A[], int l, int r, Elem& pivot) {
	do { // Move the bounds in until they meet
		while (Comp::lt(A[++l], pivot));
		while ((r != 0) && Comp::gt(A[--r], pivot));
		swap(A, l, r); // Swap out-of-place values
	} while (l < r); // Stop when they cross
	swap(A, l, r); // Reverse last swap
	return l; // Return first pos on right
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::mergesort(Elem A[], Elem temp[], int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return;
	mergesort<Elem, Comp>(A, temp, left, mid);
	mergesort<Elem, Comp>(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) // Copy
		temp[i] = A[i];
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1) // Left exhausted
			A[curr] = temp[i2++];
		else if (i2 > right) // Right exhausted
			A[curr] = temp[i1++];
		else if (Comp::lt(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::mergesort_opt(Elem A[], Elem temp[], int _left, int _right) {
	int mid = (_left + _right) / 2;
	if (_left == _right) return;
	if ((_right - _left) > 4) // Use insertion sort to sort small sublists
	{
		mergesort<Elem, Comp>(A, temp, _left, mid);
		mergesort<Elem, Comp>(A, temp, mid + 1, _right);
	}
	else
		insertsort(A);
		for (int i = _left; i <= _right; i++) // Copy
			temp[i] = A[i];
	int i1 = _left; int i2 = mid + 1;
	for (int curr = _left; curr <= _right; curr++) {
		if (i1 == mid + 1) // Left exhausted
			A[curr] = temp[i2++];
		else if (i2 > _right) // Right exhausted
			A[curr] = temp[i1++];
		else if (Comp::lt(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::heapsort(Elem A[], int n) { // Heapsort
	Elem mval;
	maxheap<Elem, Comp> H(A, n, n); // 'class maxheap' is define in the 'maxheap.h' file
	for (int i = 0; i < n; i++) // Now sort
		H.removemax(mval); // Put max at end
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::binsort(Elem A[], int n) {
	List<Elem> B[MaxKeyValue];
	Elem item;
	for (int i = 0; i < n; i++) B[A[i]].append(A[i]);
	for (int i = 0; i < MaxKeyValue; i++)
		for (B[i].setStart();
			B[i].getValue(item); B[i].next())
			output(item);
}

template <class Elem, class Comp>
void Sorting<Elem, Comp>::radix(Elem A[], Elem B[], int n, int k, int r, int cnt[]) {
	// cnt[i] stores # of records in bin[i]
	int j;
	for (int i = 0, rtok = 1; i < k; i++, rtok *= r) {
		for (j = 0; j < r; j++) cnt[j] = 0;
		// Count # of records for each bin
		for (j = 0; j < n; j++) cnt[(A[j] / rtok) % r]++;
		// cnt[j] will be last slot of bin j.
		for (j = 1; j < r; j++) cnt[j] = cnt[j - 1] + cnt[j];
		for (j = n - 1; j >= 0; j--) B[--cnt[(A[j] / rtok) % r]] = A[j];
		for (j = 0; j < n; j++) A[j] = B[j];
	}
}