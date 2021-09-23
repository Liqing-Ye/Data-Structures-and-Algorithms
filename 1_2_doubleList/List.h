#pragma once
template <class Elem>
class List
{
public:
	virtual void clear() = 0; // reinitialize the list
	virtual bool insert(const Elem&) = 0;// insert an item into the list before the current item
	virtual bool append(const Elem&) = 0;// insert an item into the list at the end of the list	
	virtual bool remove(Elem&) = 0;// remove the item at the current
	virtual void setStart() = 0;//set current to the beginning
	virtual void setEnd() = 0;// set current to the last
	virtual void prev() = 0;// set current to the previous item
	virtual void next() = 0;// set current to the next item
	virtual int leftLength()const = 0;// the size of the list before the current
	virtual int rightLength()const = 0;// the size of the list after and including the current
	virtual bool setPos(int pos) = 0;// set current to the position indicated by the argument
	virtual bool getValue(Elem&)const = 0;// return the value of the current item in the argument
	virtual void print()const = 0;// print out the items in the list
};



