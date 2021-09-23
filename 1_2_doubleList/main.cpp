#include<iostream>
#include"LList.h"

using namespace std;

int main() {
	// ²âÊÔ
	LList<int> llist;
	llist.append(20);
	llist.append(33);
	llist.append(51);
	llist.insert(99);
	llist.append(68);
	llist.setPos(2);
	llist.print();

	return 0;
}