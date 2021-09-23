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
			delete fence; //删除当前元素
		}
	}

	void clear() { //开销太大，如何优化？？
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

	bool remove(Elem& item) { //删除fence位置的下一个元素
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

	bool setPos(int pos) {// 将fence移到pos处，（pos是从0开始的）
		if ((pos < 0) || (pos > rightcnt + leftcnt)) return false; //rightcnt + leftcnt == 数量
		fence = head;
		for (int i = 0; i < pos; i++) fence = fence->next; //fence 遍历到pos位置
		rightcnt = rightcnt + leftcnt - pos;
		leftcnt = pos; // 从head->next到fence本身有多少个元素
		return true;
	}

	bool getValue(Elem& item)const { 
		if (rightcnt == 0) return false; //获得fence位置的下一个element
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

	bool swap() { //新增加一个函数：交换fence后面两个元素的位置
		if (fence == tail) return false;
		if (fence->next == tail) return false;

		Link<Elem>* temp = fence->next;
		fence->next = temp->next;
		temp->next = fence->next->next;
		fence->next->next = temp;

		if (fence->next == tail) tail = tail->next;
		return true;
	}

	bool findNdel(Elem value) { //新增加一个函数，找到所有等于value的元素并删除
		if (head == tail) return false;

		Link<Elem>* temp;
		Link<Elem>* ptr = head;
		bool beforeFence = true;

		while (ptr != tail) {
			if (ptr == fence->next) beforeFence = false;
			if (ptr->next->element == value) { //检查ptr的下一个的元素是不是等于value
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

