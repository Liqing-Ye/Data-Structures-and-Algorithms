#include"BinNodePtr.h"
#include"VarBinNode.h"
#include"BST.h"

int main() {
	BinNodePtr<int> binNodePtr; // 二叉树 ： 包含 先序，中序，后序
	VarBinNode<int> varBinNode(9); // union优化二叉树 特点： leaf node 和 internal node 的存储不同，处理函数也不同
	BST<int, int, int, int> bST; // binary search tree 特点： left child < subroot < right child

	return 0;
}