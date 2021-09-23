#pragma once
#include "Queue.h"

#define DefaultListSize 20

template <class Elem>
class AQueue : public Queue<Elem>
{
private:
	int size;  // Maximum size of queue
	int front; // Index of front element 当前队列中第一个element
	int rear;  // Index of rear element 待插入空位的前一个element
	Elem* listArray; // Array holding queue elements

public:
	AQueue(int sz = DefaultListSize) { // Make list array one position larger for empty slot
		size = sz + 1;
		rear = 0;
		front = 1;
		listArray = new Elem[size];
	}

	~AQueue() {
		delete[]listArray;
	}

	bool enqueue(const Elem& it) { // Put element on rear
		if (rear == size) return false; // Full 
		listArray[++rear] = it;
		return true;
	}

	bool dequeue(Elem& it) {   // Remove element from front
		if (length() == 0)return false; // empty queue	
		it = listArray[front++]; // it=队列中第一个element，front后移一位
		return true;
	}

	int length() {
		return rear-front+1;
	}

	//-------------------- 不懂 --------------------
	// 环形链表
	bool enqueue_circularQueue(const Elem& it) {
		if (((rear + 2) % size) == front) return false; // Full
		rear = (rear + 1) % size; // Circular increment
		listArray[rear] = it;
		return true;
	}

	bool dequeue_circularQueue(Elem& it) {
		if (length() == 0) return false; // Empty
		it = listArray[front];
		front = (front + 1) % size; // Circular increment
		return true;
	}
	//----------------------------------------------
};

