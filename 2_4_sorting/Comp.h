#pragma once

template<class Elem>
class Comp // �򵥵���ֵ�Ƚϣ�����д�ɱ�ıȽϹ���
{
public:
	bool lt(Elem, Elem); // less than
	bool gt(Elem, Elem); // greater than
	bool eq(Elem, Elem); // equal
};

