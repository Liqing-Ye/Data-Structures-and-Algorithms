#pragma once
template <class Elem>
class Stack
{
public:
	virtual bool push(const Elem&) = 0; //in
	virtual bool pop(Elem&) = 0; //out
};

