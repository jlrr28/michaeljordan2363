#include <iostream>
#include "IntBinaryTree.h"
#include <string>

using namespace std;
int main() {
	
	IntBinaryTree tree;

	tree.insertNode("abc");
	tree.insertNode("efg");
	tree.insertNode("hij");
	
	tree.displayInOrder();
	
	return 0;


}