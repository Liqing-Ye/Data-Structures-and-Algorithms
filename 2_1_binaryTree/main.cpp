#include"BinNodePtr.h"
#include"VarBinNode.h"
#include"BST.h"

int main() {
	BinNodePtr<int> binNodePtr; // ������ �� ���� �������򣬺���
	VarBinNode<int> varBinNode(9); // union�Ż������� �ص㣺 leaf node �� internal node �Ĵ洢��ͬ��������Ҳ��ͬ
	BST<int, int, int, int> bST; // binary search tree �ص㣺 left child < subroot < right child

	return 0;
}