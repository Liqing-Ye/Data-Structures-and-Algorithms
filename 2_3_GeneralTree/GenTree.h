#pragma once
#include"GTNode.h"
#include<iostream>
using namespace std;

template<class Elem> 
class GenTree // general tree ADT
{
private:
	void printhelp(GTNode*);

public:
	GenTree();
	~GenTree();

	void clear();
	GTNode* root();

	void newroot(Elem, GTNode*, GTNode*);
	void print();
};



