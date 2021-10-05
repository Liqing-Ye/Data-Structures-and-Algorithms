#include "GentreePPI.h"

int GentreePPI::FIND(int curr)const { 
	while (array[curr] != ROOT)curr = array[curr]; //һֱ׷�ݵ����ڵ�
	return curr;
}

bool GentreePPI::differ(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	return root1 != root2; // �жϸ��ڵ��Ƿ���ͬ
}

void GentreePPI::UNION(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	if (root1 != root2)array[root2] = root1; // ��root1��Ϊroot2�ĸ��ڵ㣬��ʱroot2Ϊroot1�µ�����
}