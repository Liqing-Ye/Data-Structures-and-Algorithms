#pragma once
#include<iostream>
using namespace std;

enum Nodetype{leafNode,internalNode};

template <class Operator>
class VarBinNode
{
public:
	Nodetype mytype;
	union {
		struct {  // internal node
			VarBinNode* left;  // left child
			VarBinNode* right;  // right child
			Operator opx;  // value
		} intl;
		Operator var;  // leaf: value only
	};


	VarBinNode(const Operator& val) { // leaf node 
		mytype = leafNode;
		var = val;
	}
	VarBinNode(const Operator& op, VarBinNode* l, VarBinNode* r) {  // internal node
		mytype = internalNode;
		intl.right = r;
	}

	bool isLeaf() {
		return mytype == leafNode;
	}

	VarBinNode* leftchild() {
		return intl.left;
	}

	VarBinNode* rightchild() {
		return intl.right;
	}

	void traverse(VarBinNode* subroot) { // preorder traversal
		if (subroot == NULL)return;
		if (subroot->isLeaf()) cout << "Leaf: " << subroot->var << endl;
		else {
			cout << "Internal: " << subroot->intl.opx << endl;
			traverse(subroot->leftchild());
			traverse(subroot->rightchild());
		}
	}
};

