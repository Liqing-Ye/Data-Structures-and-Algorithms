#pragma once
#include "List.h"
#include "Link.h"
#include<iostream>

using namespace std;

template <class Elem>
class LList : public List<Elem>
{
private:
	Link<Elem>* head;
	Link<Elem>* tail;
	Link<Elem>* fence;
	int leftcnt;
	int rightcnt;
	
public:
	LList() {
		fence = head = tail = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	~LList() {
		while (head != NULL) {
			fence = head;
			head = head->next;
			delete fence; //ɾ����ǰԪ��
		}
	}

	void clear() { //����̫������Ż�����
		while (head != NULL) {
			fence = head;
			head = head->next;
			delete fence; 
		}
		fence = head = tail = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	bool insert(const Elem& item) {
		fence->next = new Link<Elem>(item, fence->next);
		if (tail == fence) tail = fence->next;
		rightcnt++;
		return true;
	}

	bool append(const Elem& item) {
		tail = tail->next = new Link<Elem>(item, NULL);
		rightcnt++;
		return true;
	}

	bool remove(Elem& item) { //ɾ��fenceλ�õ���һ��Ԫ��
		if (fence->next == NULL) return false;
		item = fence->next->element;
		Link<Elem>* ltemp = fence->next;
		fence->next = ltemp->next;
		if (tail == ltemp) tail = fence;
		delete ltemp;
		rightcnt--;
		return true;
	}

	void setStart() {
		fence = head;
		rightcnt += leftcnt;
		leftcnt = 0;
	}

	void setEnd() {
		fence = tail;
		leftcnt += rightcnt;
		rightcnt = 0;
	}

	void prev() {
		if (fence == head) return; 
		Link<Elem>* ltemp = head;
		while (ltemp->next != fence) ltemp = ltemp->next;
		fence = ltemp;
		leftcnt--;
		rightcnt++;
	}

	void next() {
		if (fence == tail) return;
		fence = fence->next;
		leftcnt++;
		rightcnt--;
	}

	int leftLength()const {
		return leftcnt;
	}

	int rightLength()const {
		return rightcnt;
	}

	bool setPos(int pos) {// ��fence�Ƶ�pos������pos�Ǵ�0��ʼ�ģ�
		if ((pos < 0) || (pos > rightcnt + leftcnt)) return false; //rightcnt + leftcnt == ����
		fence = head;
		for (int i = 0; i < pos; i++) fence = fence->next; //fence ������posλ��
		rightcnt = rightcnt + leftcnt - pos;
		leftcnt = pos; // ��head->next��fence�����ж��ٸ�Ԫ��
		return true;
	}

	bool getValue(Elem& item)const { 
		if (rightcnt == 0) return false; //���fenceλ�õ���һ��element
		item = fence->next->element;
		return true;
	}

	void print()const {
		Link<Elem>* temp = head;
		cout << "<";
		int i = 0;
		while (temp != fence){
			cout << temp->next->element << " ";
			temp = temp->next;
		}
		cout <<  '|';
		while (temp->next != NULL) {
			cout << temp->next->element << " ";
			temp = temp->next;
		}
		cout << '>' << endl;
	}

	bool swap() { //������һ������������fence��������Ԫ�ص�λ��
		if (fence == tail) return false;
		if (fence->next == tail) return false;

		Link<Elem>* temp = fence->next;
		fence->next = temp->next;
		temp->next = fence->next->next;
		fence->next->next = temp;

		if (fence->next == tail) tail = tail->next;
		return true;
	}

	bool findNdel(Elem value) { //������һ���������ҵ����е���value��Ԫ�ز�ɾ��
		if (head == tail) return false;

		Link<Elem>* temp;
		Link<Elem>* ptr = head;
		bool beforeFence = true;

		while (ptr != tail) {
			if (ptr == fence->next) beforeFence = false;
			if (ptr->next->element == value) { //���ptr����һ����Ԫ���ǲ��ǵ���value
				if (fence == ptr->next)fence = ptr;
				if (tail==ptr->next)tail = ptr;
				temp = ptr->next;
				ptr->next = ptr->next->next;
				delete temp;
				if (beforeFence)leftcnt--;
				else rightcnt++;
			}
			else ptr = ptr->next;
		}
		return true;
	}
};

