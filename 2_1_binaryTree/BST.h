#pragma once
#include"BinNode.h"
#include"BinNodePtr.h"
template <class Key, class Elem, class KEComp, class EEComp>
class BST //: public BinNode<Elem>
{
private:
	BinNode<Elem>* root; // root of the binary search tree(BST)
	int nodecount;  // number of nodes

	void clearhelp(BinNode<Elem>*);
	BinNode<Elem>* inserthelp(BinNode<Elem>*, const Elem&);
	BinNode<Elem>* deletemin(BinNode<Elem>*, BinNode<Elem>*&);
	BinNode<Elem>* removehelp(BinNode<Elem>*, const Key&, const Elem*&);
	bool findhelp(BinNode<Elem>*, const Key&, Elem&)const;
	void printhelp(BinNode<Elem>*, int)const;

public:
	BST() {
		root = NULL;
		nodecount = 0;
	}
	~BST() {
		clearhelp(root);
	}

	void clear();
	bool insert(const Elem&);
	bool remove(const Key& K, Elem&);
	bool removeAny(Elem&);
	bool find(const Key&, Elem&)const;
	int size();
	void print()const;
};


// private function: 

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::clearhelp(BinNode<Elem>* subroot) {
	if (subroot == NULL)return;
	clearhelp(subroot->left());
	clearhelp(subroot->right());
	delete subroot; // delete the node
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::inserthelp(BinNode<Elem>* subroot, const Elem& val) {
	if (subroot == NULL) return new BinNodePtr<Elem>(val, NULL, NULL);
	if (EEComp::lt(val, subroot->val())) subroot->setLeft(inserthelp(subroot->left(), val)); // 若val<left child, 则向left subroot tree插入数据
	else subroot->setRight(inserthelp(subroot->right(), val)); // 若val>left child, 则向right subroot tree插入数据
	return subroot;
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::deletemin(BinNode<Elem>* subroot, BinNode<Elem>*& min) {
	if (subroot->left() == NULL) {
		min = subroot;
		return subroot->right(); // 删掉最小值后，用它的右孩子（树）接替它的位置，所以要返回右孩子（树）的地址
	}
	else {
		subroot->setLeft(deletemin(subroot->left(), min)); // 用它的右孩子（树）接替它的位置
		return subroot;
	}
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::removehelp(BinNode<Elem>* subroot, const Key& K, const Elem*& t) {
	if (subroot == NULL)return NULL; // can not find the target
	else if (KEComp::lt(K, subroot->val()))subroot->setLeft(removehelp(subroot->left(), K, t)); // search the target
	else if (KEComp::gt(K, subroot->val()))subroot->setRight(removehelp(subroot->right(), K, t)); // search the target
	else { // found the target 
		BinNode<Elem>* temp;
		t = subroot;
		if (subroot->left() == NULL)subroot = subroot->right(); // K has no left child
		else if (subroot->right() == NULL)subroot = subroot->left(); // K has no left and right child
		else { // both childen are non-empty
			subroot->setRight(deletemin(subroot->right(), temp));  // find the minimum value(temp) which lager than K
			Elem te = subroot->val();
			subroot->setVal(temp->val()); //  use "the minimum value(temp) which lager than K" instead of K
			temp->setVal(te);
			t = temp; // return the removed value's pointer to parameter of t
		}
	}
	return subroot;
}

template <class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::findhelp(BinNode<Elem>* subroot, const Key& K, Elem& e)const { // 找K， 返回给e
	if (subroot == NULL)return false; // empty subroot
	if (subroot->val() == K) {
		e = subroot->val();
		return true;
	}
	else if(findhelp(subroot->left())) return true;
	else return findhelp(subroot->right());
	//return findhelp(subroot->left())||findhelp(subroot->right())
}

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::printhelp(BinNode<Elem>* subroot, int level)const { // 中序搜索输出值，每个值前面的空格的数目 代表 它在树的第几层
	if (subroot == NULL)return NULL;
	printhelp(subroot->left(), level + 1);
	for (int i = 0; i < level; i++) cout << " ";
	cout << subroot->val() << endl;
	printhelp(subroot->right(), level + 1);
}