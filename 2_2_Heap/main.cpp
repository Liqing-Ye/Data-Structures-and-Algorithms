#include"maxheap.h"

int main() {
	int h[100][5] = { 0 }; // heap array with 100 nodes
	h[1][0] = 9; //the value in the tree inserted in advance by this way
	maxheap<int, int> maxheapObj(&h[0][0], 0, 100); // complete binary tree

	return 0;
}