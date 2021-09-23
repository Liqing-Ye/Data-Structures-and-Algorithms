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
		if (size == 0) return false; // ����Ƿ���Ԫ�ؿ����ó�
		it = top->element; // ���������Ԫ�����
		Link<Elem>* ltemp = top->next; // ���� �µ��������Ԫ�صĵ�ַ
		delete top; // ɾ���������Ԫ��
		top = ltemp; // �޸�topΪ�µ�������Ԫ�صĵ�ַ
		size--; // ������-1
		return true;
	}

	void clear() {
		while (top != NULL) {
			Link<Elem>* ltemp = top->next; // ���� �µ��������Ԫ�صĵ�ַ
			delete top; // ɾ���������Ԫ��
			top = ltemp; // �޸�topΪ�µ�������Ԫ�صĵ�ַ
		}
		size = 0;
	}
};

