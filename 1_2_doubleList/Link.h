#pragma once
#include<iostream>

template <class Elem>
class Link  //double-linked list link node
{
public:
	Elem element;  //value of this node
	Link* next;  // pointer of next node
	Link* prev;  //pointer of previous node
	Link(const Elem& e, Link* prevp = NULL, Link* nextp = NULL) {
		element = e;
		prev = prevp;
		next = nextp;
	}
	Link(Link* prevp = NULL, Link* nextp = NULL) {
		prev = prevp;
		next = nextp;
	}
};

