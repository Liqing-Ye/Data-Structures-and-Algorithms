#pragma once

template<class Elem>
class GTNode // general tree node ADT
{
public:
	GTNode(const Elem&);
	~GTNode();
	Elem value(); // return value
	bool isLeaf(); // TRUE if is a leaf
	GTNode* leftmost_child(); // First child
	GTNode* right_sibling(); // Right sibling
	void setValue(Elem&); // set value
	void insert_first(GTNode<Elem>* n); 
	void insert_next(GTNode<Elem>* n);
	void remove_first(); // remove first child
	void remove_next(); // remove sibling
};

