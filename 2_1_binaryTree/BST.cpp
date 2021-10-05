#include "BST.h"

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::clear() { // reset the tree
	clearhelp(root);
	root = NULL;
	nodecount = 0;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::insert(const Elem& e) {
	root = inserthelp(root, e);
	nodecount++;
	return true;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::remove(const Key& K, Elem& e) { // ɾ��Ԫ��K�������ظ� Elem& e
	BinNode<Elem>* t = NULL;
	root = removehelp(root, K, t); // ɾ��Ԫ��K
	if (t == NULL)return false; // ��δɾ���ɹ�
	e = t->val(); // ��ɾ����Ԫ��ֵ���ظ� Elem& e
	nodecount--;
	delete t;
	return true;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::removeAny(Elem& e) { // ����root=___(root,t) �������õĲ�ͬ��ʵ�ֲ�ͬ�Ĺ���
	if (root == NULL)return false;
	BinNode<Elem>* t;
	root = deletemin(root, t);  // remove the min value
	e = t->val();
	delete t;
	nodecount--;
	return true;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::find(const Key& K, Elem& e)const {
	return findhelp(root, K, e);
}

template <class Key, class Elem, class KEComp, class EEComp>
int BST<Key, Elem, KEComp, EEComp>::size() {
	return nodecount;
}

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::print()const {
	if (root == NULL) cout << "The BST is empty.\n";
	else printhelp(root, 0);
}
