#include "GenTree.h"

template<class Elem>
void GenTree<Elem>::printhelp(GTNode<Elem>* subroot) {  // traversal 1
	if (subroot->isLeaf())cout << "Leaf: ";
	else cout << "Internal: ";;
	cout << subroot->value() << endl;
	for (GTNode<Elem>* temp = subroot->leftmost_child(); temp != NULL; temp = temp->right_sibling())printhelp(temp); // œ»–Ú
}

#ifdef 0
template<class Elem>
void GenTree<Elem>::printhelp(GTNode<Elem>* subroot) { // traversal 2
	if (subroot == NULL)return;
	if (subroot->isLeaf())cout << "Leaf: ";
	else cout << "Internal: ";;
	cout << subroot->value() << endl;
	printhelp(subroot->leftmost_child); // œ»–Ú
	printhelp(sunroot->right_sibling);
}
#endif // 0
