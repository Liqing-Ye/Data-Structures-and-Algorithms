#pragma once

template<class Elem>
class Comp // 简单的数值比较，可重写成别的比较规则
{
public:
	bool lt(Elem, Elem); // less than
	bool gt(Elem, Elem); // greater than
	bool eq(Elem, Elem); // equal
};

