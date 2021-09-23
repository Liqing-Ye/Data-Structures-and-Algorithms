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
			delete fence; //ɾ����ǰԪ��
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
		fence->next = new Link<Elem>(item, fence, fence->next); // ��fence�������һ��element
		if (fence->next->next != NULL) fence->next->next->prev = fence; // �޸�element�ĺ�һ��Ԫ�ص�prevΪelement�ĵ�ַ
		if (tail == fence) tail = fence->next; // �޸�tail
		rightcnt++; // fence�����һ��Ԫ��
		return true;
	}

	bool append(const Elem& item) {
		tail = tail->next = new Link<Elem>(item, NULL);
		rightcnt++;
		return true;
	}

	bool remove(Elem& it) { //remove the fist element in right part (ɾ��fence�ұߵĵ�һ��Ԫ��)
		if (fence->next == NULL) return false;  // ����Ƿ��п�ɾ����Ԫ��
		it = fence->next->element; // ��¼��ɾ����Ԫ��
		Link<Elem>* ltemp = fence->next; // ��¼��ɾ��Ԫ�صĵ�ַ
		if (ltemp->next != NULL) ltemp->next->prev = fence; // �޸Ĵ�ɾ��Ԫ�صĺ�һ����prev
		else tail = fence; // ����ɾ����Ԫ��Ϊtail���޸�tailָ��ĵ�ַ
		fence->next = ltemp->next; // �޸�fence->nextָ��ĵ�ַ
		delete ltemp; // ɾ�� ��ɾ����Ԫ��
		rightcnt--; // �ұߵ�Ԫ�ظ�����һ
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

	void prev() { //��fence��ǰ��һ��Ԫ��
		if (fence != head) { // ���fenceǰ����Ԫ��
			fence = fence->prev; // ��fenceǰ��һ��Ԫ��
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

	bool setPos(int pos) { // ��fence�Ƶ�pos������pos�Ǵ�0��ʼ�ģ�
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

	void print()const { // ��fence���滭��|��
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

