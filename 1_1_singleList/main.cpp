#include<iostream>
#include "ArrayList.h"
#include "LList.h"
using namespace std;

int main(int argc, int* argv[])
{
	// 数组型链表
	ArrayList<int> arrayList;
	arrayList.append(2);
	arrayList.append(23);
	arrayList.append(15);
	arrayList.append(5);
	arrayList.append(9);
	arrayList.setPos(2);
	arrayList.print();

	// 指针型单向链表
	int temp;
	LList<int> height;
	height.append(163);
	height.append(172);
	height.setPos(1);
	height.insert(180);
	height.prev();
	height.remove(temp);
	cout << "被删除的数据： " << temp << endl;
	height.print();
}