#include<iostream>
#include "AStack.h"
#include "LStack.h"
using namespace std;

int main(int argc, int* argv[])
{
	// ������ջ��
	int out;
	AStack<int> aStack;
	aStack.push(2);
	aStack.push(6);
	aStack.push(78);
	aStack.pop(out);
	cout << "��������ջ�����ó���һ��Ԫ�أ�" << out << endl;

	// ָ���� ����ջ��
	LStack<int> lStack;
	lStack.push(2);
	lStack.push(45);
	lStack.push(98);
	lStack.pop(out);
	cout << "��������ջ�����ó���һ��Ԫ�أ�" << out << endl;
}