#pragma once
#include"BinNode.h"

template <class Elem>
class BinNodePtr : public BinNode<Elem> {  // Binary tree node class
private:
	Elem it; // The node's value
	BinNodePtr* lc; // Pointer to left child
	BinNodePtr* rc; // Pointer to right child

public:
	BinNodePtr() { 
		it = NULL;
		lc = rc = NULL;
	}
	BinNodePtr(Elem e, BinNodePtr* l = NULL, BinNodePtr* r = NULL)
	{
		it = e; 
		lc = l; 
		rc = r;
	}

	Elem& val() { 
		return it; 
	}
	void setVal(const Elem& e) { 
		it = e; 
	}
	inline BinNode<Elem>* left() const{
		return lc;
	}
	void setLeft(BinNode<Elem>* b){
		lc = (BinNodePtr*)b;
	}
	inline BinNode<Elem>* right() const{
		return rc;
	}
	void setRight(BinNode<Elem>* b){
		rc = (BinNodePtr*)b;
	}
	bool isLeaf(){
		return (lc == NULL) && (rc == NULL);
	}

	void preorder(BinNode<Elem>*); // 先序
	void inorder(BinNode<Elem>*); // 中序
	void postorder(BinNode<Elem>*); // 后序
	int findHeight(BinNode<Elem>*); // 计算树的高度 ：height of tree
	bool search(BinNode<Elem>*, Elem); // 找K，找到了就返回true
};

