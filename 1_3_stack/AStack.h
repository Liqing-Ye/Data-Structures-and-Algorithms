#pragma once
#include "Stack.h"

#define DefaultListSize 20

template <class Elem>
class AStack : public Stack<Elem>
{
private:
	int maxSize; //Maximum size of stack
	int top; // Index for top element ��¼��ǰԪ�ص�λ��
	Elem* listArray; // Array holding stack elements

public:
	AStack(int size = DefaultListSize) {
		maxSize = size;
		top = 0;
		listArray = new Elem[size];
	}

	~AStack() {
		delete[] listArray;
	}

	bool push(const Elem& it) { // put it on stack
		if (top == maxSize) return false; // ����Ƿ��п�λ��������
		listArray[top++] = it;
		return true;
	}

	bool pop(Elem& it) { // pop top element
		if (top == 0) return false; // ����Ƿ���Ԫ�ؿ����ó�
		it = listArray[--top]; // top��λ��ָ���һ���ո��λ��p��p��0��ʼ����--topָ����������Ǹ�Ԫ��
		return true;
	}
};

