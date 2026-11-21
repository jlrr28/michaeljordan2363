#include <iostream>
#include "IntBinaryTree.h"
#include <string>

using namespace std;
int main() {
	
	IntBinaryTree tree;

	tree.insertNode(5);
	tree.insertNode(10);
	tree.insertNode(6);
	
	tree.displayInOrder();
	
	return 0;


}