#pragma once

#include "List.h"
#include "Link.h"

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

	void clear() {
		while (head != NULL) {
			fence = head;
			head = head->next;
			delete fence;
		}
		fence = head = tail = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	bool insert(const Elem& item) { //insert at the front of right partition
		fence->next = new Link<Elem>(item, fence, fence->next); // 在fence后面插入一个element
		if (fence->next->next != NULL) fence->next->next->prev = fence; // 修改element的后一个元素的prev为element的地址
		if (tail == fence) tail = fence->next; // 修改tail
		rightcnt++; // fence后面加一个元素
		return true;
	}

	bool append(const Elem& item) {
		tail = tail->next = new Link<Elem>(item, NULL);
		rightcnt++;
		return true;
	}

	bool remove(Elem& it) { //remove the fist element in right part (删除fence右边的第一个元素)
		if (fence->next == NULL) return false;  // 检查是否有可删除的元素
		it = fence->next->element; // 记录待删除的元素
		Link<Elem>* ltemp = fence->next; // 记录待删除元素的地址
		if (ltemp->next != NULL) ltemp->next->prev = fence; // 修改待删除元素的后一个的prev
		else tail = fence; // 若待删除的元素为tail，修改tail指向的地址
		fence->next = ltemp->next; // 修改fence->next指向的地址
		delete ltemp; // 删除 待删除的元素
		rightcnt--; // 右边的元素个数减一
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

	void prev() { //将fence往前移一个元素
		if (fence != head) { // 如果fence前面有元素
			fence = fence->prev; // 将fence前移一个元素
			leftcnt--;
			rightcnt++;
		}
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

	bool setPos(int pos) { // 将fence移到pos处，（pos是从0开始的）
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

	void print()const { // 在fence后面画“|”
		Link<Elem>* temp = head;
		cout << "<";
		int i = 0;
		while (temp != fence) {
			cout << temp->next->element << " ";
			temp = temp->next;
		}
		cout << '|';
		while (temp->next != NULL) {
			cout << temp->next->element << " ";
			temp = temp->next;
		}
		cout << '>' << endl;
	}
};

