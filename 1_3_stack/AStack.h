#pragma once
#include "Stack.h"

#define DefaultListSize 20

template <class Elem>
class AStack : public Stack<Elem>
{
private:
	int maxSize; //Maximum size of stack
	int top; // Index for top element 记录当前元素的位置
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
		if (top == maxSize) return false; // 检查是否有空位放入数据
		listArray[top++] = it;
		return true;
	}

	bool pop(Elem& it) { // pop top element
		if (top == 0) return false; // 检查是否有元素可以拿出
		it = listArray[--top]; // top的位置指向第一个空格的位置p（p从0开始），--top指向最上面的那个元素
		return true;
	}
};

