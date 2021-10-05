#include "Comp.h"

template<class Elem>
bool Comp<Elem>::lt(Elem i, Elem j) {
	return i <= j;
}

template<class Elem>
bool Comp<Elem>::gt(Elem i, Elem j) {
	return i > j;
}

template<class Elem>
bool Comp<Elem>::eq(Elem i, Elem j) {
	return i == j;
}