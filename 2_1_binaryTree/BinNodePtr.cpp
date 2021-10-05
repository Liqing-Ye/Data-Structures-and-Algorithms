#include "BinNodePtr.h"

template <class Elem>
void BinNodePtr<Elem>::preorder(BinNode<Elem>* subroot) { // 先序
	visit(subroot);  // 缺点：可能会遇到root=NULL （依然调用了visit()函数）的情况
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
}

template <class Elem>
void BinNodePtr<Elem>::inorder(BinNode<Elem>* subroot) { // 中序
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	visit(subroot);
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
}

template <class Elem>
void BinNodePtr<Elem>::postorder(BinNode<Elem>* subroot) { // 后序
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
	visit(subroot);
}

template <class Elem>
int BinNodePtr<Elem>::findHeight(BinNode<Elem>* subroot) { // 计算树的高度 ：height of tree
	if (subroot == NULL)return 0; // empty subroot
	return 1 + max(height(subroot->left()), height(subroot->right()));
}

template <class Elem>
bool BinNodePtr<Elem>::search(BinNode<Elem>* subroot, Elem K) { // 找K，找到了就返回true
	if (subroot == NULL)return false; // empty subroot
	if (subroot->value() == K) return true;
	else if (search(subroot->left())) return true;
	else return search(subroot->right());
}