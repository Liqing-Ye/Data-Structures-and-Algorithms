#include<iostream>
#include "AStack.h"
#include "LStack.h"
using namespace std;

int main(int argc, int* argv[])
{
	// 数组型栈堆
	int out;
	AStack<int> aStack;
	aStack.push(2);
	aStack.push(6);
	aStack.push(78);
	aStack.pop(out);
	cout << "从数组型栈堆中拿出来一个元素：" << out << endl;

	// 指针型 链表栈堆
	LStack<int> lStack;
	lStack.push(2);
	lStack.push(45);
	lStack.push(98);
	lStack.pop(out);
	cout << "从链表型栈堆中拿出来一个元素：" << out << endl;
}