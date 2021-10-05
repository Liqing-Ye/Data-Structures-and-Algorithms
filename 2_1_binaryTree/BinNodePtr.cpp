#include "BinNodePtr.h"

template <class Elem>
void BinNodePtr<Elem>::preorder(BinNode<Elem>* subroot) { // ����
	visit(subroot);  // ȱ�㣺���ܻ�����root=NULL ����Ȼ������visit()�����������
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
}

template <class Elem>
void BinNodePtr<Elem>::inorder(BinNode<Elem>* subroot) { // ����
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	visit(subroot);
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
}

template <class Elem>
void BinNodePtr<Elem>::postorder(BinNode<Elem>* subroot) { // ����
	if (subroot->left() != NULL) preorder(subroot->left()); // go to the left child
	if (subroot->right() != NULL) preorder(subroot->right()); // go to the right child
	visit(subroot);
}

template <class Elem>
int BinNodePtr<Elem>::findHeight(BinNode<Elem>* subroot) { // �������ĸ߶� ��height of tree
	if (subroot == NULL)return 0; // empty subroot
	return 1 + max(height(subroot->left()), height(subroot->right()));
}

template <class Elem>
bool BinNodePtr<Elem>::search(BinNode<Elem>* subroot, Elem K) { // ��K���ҵ��˾ͷ���true
	if (subroot == NULL)return false; // empty subroot
	if (subroot->value() == K) return true;
	else if (search(subroot->left())) return true;
	else return search(subroot->right());
}