#include<iostream>
#include "ArrayList.h"
#include "LList.h"
using namespace std;

int main(int argc, int* argv[])
{
	// ����������
	ArrayList<int> arrayList;
	arrayList.append(2);
	arrayList.append(23);
	arrayList.append(15);
	arrayList.append(5);
	arrayList.append(9);
	arrayList.setPos(2);
	arrayList.print();

	// ָ���͵�������
	int temp;
	LList<int> height;
	height.append(163);
	height.append(172);
	height.setPos(1);
	height.insert(180);
	height.prev();
	height.remove(temp);
	cout << "��ɾ�������ݣ� " << temp << endl;
	height.print();
}