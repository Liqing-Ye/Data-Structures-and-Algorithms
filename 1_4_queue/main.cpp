#include<iostream>
#include"LQueue.h"
#include"AQueue.h"

using namespace std;

int main() {
	int temp;
	AQueue<int> aQueue;
	aQueue.enqueue(2);
	aQueue.enqueue(5);
	aQueue.enqueue(66);
	aQueue.dequeue(temp);
	cout << temp << endl;
	aQueue.dequeue(temp);
	cout << temp << endl;
	aQueue.dequeue(temp);
	cout << temp << endl;

	cout << endl;

	LQueue<int> lQueue;
	lQueue.enqueue(21);
	lQueue.enqueue(51);
	lQueue.enqueue(616);
	lQueue.dequeue(temp);
	cout << temp << endl;
	lQueue.dequeue(temp);
	cout << temp << endl;
	lQueue.dequeue(temp);
	cout << temp << endl;
	return 0;
}