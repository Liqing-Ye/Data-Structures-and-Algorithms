#pragma once
#include<iostream>
using namespace std;

template <class Elem>
class BinNode
{
public:
	virtual Elem& val() = 0; // get the value 
	virtual BinNode* left() const = 0; // get the left child pointer
	virtual BinNode* right() const = 0; // get the right child pointer
	virtual void setVal(const Elem&) = 0; // set the value
	virtual void setLeft(BinNode*) = 0; // set the left child pointer
	virtual void setRight(BinNode*) = 0; // set the right child pointer 
	virtual bool isLeaf() = 0; // check whether the pointer is a leaf or not
};

