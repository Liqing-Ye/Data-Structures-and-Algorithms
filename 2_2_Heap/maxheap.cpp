#include "maxheap.h"

template<class Elem,class Comp>
void maxheap<Elem, Comp>::buildHeap() { // ���α���ÿ��internal node�� �ֱ�һ������ֱ���������������
	for (int i = n / 2 - 1; i >= 0; i--)siftdown(i); // do not need to call siftdown function on leaf nodes (eg: n = 9, internal node = 9/2 = 4,index of 4 = 4-1 = 3) 
}

template<class Elem, class Comp>
void maxheap<Elem, Comp>::siftdown(int pos) { // ����pos��internal node����������ʵ����ȷ����
	while (!isLeaf(pos)) { // internal node
		int j = leftchild(pos); // j mark the position of the maximum value of two children
		int rc = rightchild(pos); // the position of right child
		if ((rc < n) && Comp::lt(Heap[j], Heap[rc]))j = rc; // check right child is not null && Heap[j] is smaller
		if (!Comp::lt(Heap[pos], Heap[j]))return; // check Heap[pos] is larger than the maximum child value Heap[j], should not to swap
		swap(Heap, pos, j); // swap the Heap[pos] and Heap[j]
		pos = j;  // ��swap����j�������費��Ҫ�ٵ���
	}
}

template<class Elem, class Comp>
bool maxheap<Elem, Comp>::removemax(Elem& it) { // ȡ��max����������������
	if (n == 0)return false; // empty heap
	swap(Heap, 0, --n); // swap max (Heap[0]) with end (Heap[--n])
	if (n != 0)siftdown(0); // if the tree has more than one node, reorder the tree 
	it = Heap[n]; // return the maximun value of the tree
	return true;
}

template<class Elem, class Comp>
bool maxheap<Elem, Comp>::remove(int pos, Elem& it) { // remove Heap[pos]
	bool flag = false; // whether swap
	if ((pos < 0) || (pos >= n)) return false; // cheak the pos valid 
	swap(Heap, pos, --n); // swap pos with end
	while ((pos != 0) && (Comp::gt(Heap[pos], Heap[parent(pos)]))) { // has parent && lager than parent
		swap(Heap, pos, parent(pos)); // swap pos with parent
		pos = parent(pos); // now the value is in the position of parent
		flag = true;
	}
	if (!flag)siftdown(pos); // Ҫswap pos with parent ��˵��pos������һ���ȸ�ֵС���ʲ���Ҫ�ټ�����ǡ�����Ҫ�����������������
	it = Heap[n]; // return Heap[pos]
	return true;
}

template<class Elem, class Comp>
bool maxheap<Elem, Comp>::insert(const Elem& val) { // insert value
	if (n >= size)return false; // heap is full
	int curr = n++;
	Heap[curr] = val; //insert at the end of heap
	while ((curr != 0) && (Comp::gt(Heap[curr], Heap[parrent(curr)]))) { // sift up until curr's parent > curr
		swap(Heap, curr, parent(curr));
		curr = parent(curr);
	}
	return true;
}

template<class Elem, class Comp>
int maxheap<Elem, Comp>::heapsize()const {
	return size;
}

template<class Elem, class Comp>
bool maxheap<Elem, Comp>::isLeaf(int pos)const {
	if (leftchild(pos) == NULL && rightchild(pos) == NULL)return true;
	return false;
}

template<class Elem, class Comp>
int maxheap<Elem, Comp>::leftchild(int pos)const {
	return Heap[pos][1];
}

template<class Elem, class Comp>
int maxheap<Elem, Comp>::rightchild(int pos)const{
	return Heap[pos][2];
}

template<class Elem, class Comp>
int maxheap<Elem, Comp>::parent(int pos)const {
	return Heap[pos][0];
}

