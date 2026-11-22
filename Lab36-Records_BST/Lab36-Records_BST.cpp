//COMSC-210 || LAB 36 || JOSE LUIS RAMOS
#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
#include <string>

using namespace std;

int main_menu();

int main() {
	
	string file = "alphabet.txt";
	IntBinaryTree tree;

	ifstream fin(file);
	string in;
	while (fin >> in)
		tree.insertNode(in);
    fin.close();


	tree.displayInOrder();
	//tree.displayPostOrder();
	//tree.displayPreOrder();

    int input = 0;
    while (input != 4) {

        input = main_menu();

        switch (input) {
        case 1: {
            cout << "Enter string to insert" << endl;
            
            string insertString;
            getline(cin, insertString);
            cout << "Inserting " << insertString << endl;
            tree.insertNode(insertString);
        }
            break;
        case 2:
            tree.displayInOrder();
            break;
        case 3:

            break;
        case 4:

        default: break;
        }
    }

	return 0;


}

int main_menu() {
    int in = 0;
    cout << endl;
    cout << "Records BST" << endl;
    cout << "[1] Insert node" << endl << "[2] remove node" << endl;
    cout << "[3] Display Tree" << endl << "[4] Modify records" << endl;

    while (in < 1 || in > 4) {
        cout << "choice -->";
        cin >> in;
        if (in < 1 || in > 4)
            cout << "Invalid input\n" << endl;
    }

    return in;
};