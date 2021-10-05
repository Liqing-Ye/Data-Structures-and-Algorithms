#include "GentreePPI.h"

int GentreePPI::FIND(int curr)const { 
	while (array[curr] != ROOT)curr = array[curr]; //一直追溯到跟节点
	return curr;
}

bool GentreePPI::differ(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	return root1 != root2; // 判断根节点是否相同
}

void GentreePPI::UNION(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	if (root1 != root2)array[root2] = root1; // 让root1作为root2的根节点，此时root2为root1下的子树
}