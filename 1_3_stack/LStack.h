#pragma once
#include "Stack.h"
#include "Link.h"
#include<iostream>

#define DefaultListSize 20

template <class Elem>
class LStack : public Stack<Elem>
{
private:
	int size; // Number of elements
	Link<Elem>* top;// Pointer to first element 

public:
	LStack(int sz = DefaultListSize) {
		top = NULL;
		size = 0;
	}

	~LStack() {
		clear();
	}

	bool push(const Elem& it) {
		top = new Link<Elem>(it, top);
		size++;
		return true;
	}

	bool pop(Elem& it) {
		if (size == 0) return false; // 检查是否有元素可以拿出
		it = top->element; // 将最上面的元素输出
		Link<Elem>* ltemp = top->next; // 保存 新的最上面的元素的地址
		delete top; // 删除最上面的元素
		top = ltemp; // 修改top为新的最上面元素的地址
		size--; // 链表长度-1
		return true;
	}

	void clear() {
		while (top != NULL) {
			Link<Elem>* ltemp = top->next; // 保存 新的最上面的元素的地址
			delete top; // 删除最上面的元素
			top = ltemp; // 修改top为新的最上面元素的地址
		}
		size = 0;
	}
};

