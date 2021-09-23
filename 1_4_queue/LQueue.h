#pragma once
#include "Queue.h"
#include "Link.h"

template <class Elem>
class LQueue : public Queue<Elem>
{
private:
	Link<Elem>* front;  // Pointer to front queue node  ��ǰ�����е�һ��element
	Link<Elem>* rear;   // Pointer to rear queue node	�������λ��ǰһ��element
	int size;			// Number of elements in queue

public:
	LQueue() {
		front = NULL; 
		rear = NULL; 
		size = 0;
	}

	~LQueue() {
		clear();
	}

	bool enqueue(const Elem& it) {  // Put element on rear
		if (rear == NULL) // Empty queue
			front = rear = new Link<Elem>(it, NULL);
		else { // Append new node
			rear->next = new Link<Elem>(it, NULL);
			rear = rear->next;
		}
		size++;
		return true;
	}

	bool dequeue(Elem& it) {  // Remove element from front
		if (size == 0) return false; // Empty
		it = front->element; // Store dequeued value
		Link<Elem>* ltemp = front; // Hold dequeued link
		front = front->next; // Advance front
		delete ltemp; // Delete link
		if (front == NULL) rear = NULL; // Dequeued last element �����ɾ������Ψһ��һ��element��Ҫ�޸�rearָ��NULLs
		size--;
		return true; // Return element value
	}
	
	void clear() {
		while (front != NULL) {
			rear = front;
			front = front->next;
			delete rear;
		}
		size = 0;
	}
};

