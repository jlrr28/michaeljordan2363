#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
#include <string>

using namespace std;
int main() {
	
	string file = "alphabet.txt";
	IntBinaryTree tree;

	ifstream fin(file);
	string in;
	while (fin >> in)
		tree.insertNode(in);
	
	tree.displayInOrder();
	tree.displayPostOrder();
	tree.displayPreOrder();

	return 0;


}