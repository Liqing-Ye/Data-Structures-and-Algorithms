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

	void preorder(BinNode<Elem>*); // ����
	void inorder(BinNode<Elem>*); // ����
	void postorder(BinNode<Elem>*); // ����
	int findHeight(BinNode<Elem>*); // �������ĸ߶� ��height of tree
	bool search(BinNode<Elem>*, Elem); // ��K���ҵ��˾ͷ���true
};

