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
bool BST<Key, Elem, KEComp, EEComp>::remove(const Key& K, Elem& e) { // 删除元素K，并返回给 Elem& e
	BinNode<Elem>* t = NULL;
	root = removehelp(root, K, t); // 删除元素K
	if (t == NULL)return false; // 若未删除成功
	e = t->val(); // 将删除的元素值返回给 Elem& e
	nodecount--;
	delete t;
	return true;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::removeAny(Elem& e) { // 根据root=___(root,t) 函数调用的不同而实现不同的功能
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
