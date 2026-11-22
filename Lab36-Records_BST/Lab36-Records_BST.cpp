//COMSC-210 || LAB 36 || JOSE LUIS RAMOS
#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
#include <string>

using namespace std;

int main_menu();
void displayTreeMenu(IntBinaryTree BST);

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
    while (input != 6) {

        input = main_menu();

        switch (input) {
        case 1: {
            cout << "Enter string to insert" << endl;
            cin.ignore();
            string insertString;
            getline(cin, insertString);
            
            cout << "Inserting " << insertString << endl;
            tree.insertNode(insertString);
        }
            break;
        case 2: {
            cout << "Enter node to search for" << endl;
            cin.ignore();
            string searchString;
            getline(cin, searchString);
            cout << "Searching " << searchString << endl;

            if (tree.searchNode(searchString))
                cout << searchString << " found" << endl;
            else
                cout << searchString << " not found" << endl;
            
            break;
        }
        case 3: {//delete node
            cout << "Enter node to delete:" << endl;
            cin.ignore();
            string deleteString;
            getline(cin, deleteString);

            tree.remove(deleteString);

            if (tree.searchNode(deleteString))
                cout << deleteString << " not deleted, why?" << endl;
            else
                cout << deleteString << " deleted" << endl;

            break;

        }
        case 4: {//modify node
            cout << "Enter node to modify:" << endl;
            cin.ignore();
            string modifyString;
            getline(cin, modifyString);
            cout << "Enter new data:" << endl;
            //cin.ignore();
            string newString;
            getline(cin, newString);
            
            if (tree.searchNode(modifyString)) {
                tree.modify(modifyString, newString);
                cout << modifyString << " modified to " << newString << endl;
            }
            else
                cout << modifyString << " not found, can't modify" << endl;

            break;

        }
        case 5://display tree
            displayTreeMenu(tree);
            break;

        default: break;
        }
    }

	return 0;


}

int main_menu() {
    int in = 0;
    cout << endl;
    cout << "Records BST" << endl;
    cout << "[1] Insert node" << endl << "[2] search node" << endl;
    cout << "[3] Display Tree" << endl << "[4] Modify records" << endl;
    cout << "[5] display tree" << endl;

    while (in < 1 || in > 5) {
        cout << "choice -->";
        cin >> in;
        if (in < 1 || in > 5)
            cout << "Invalid input\n" << endl;
    }

    return in;
};

void displayTreeMenu(IntBinaryTree BST) {
    int in = 0;
    cout << endl;
    cout << "Records BST" << endl;
    cout << "[1] Display In Order" << endl << "[2] Display Post Order" << endl;
    cout << "[3] Display " << endl;
    
    while (in < 1 || in > 3) {
        cout << "choice -->";
        cin >> in;
        switch (in) {
        case 1:
            BST.displayInOrder()
                break;
        case 2
            BST.
            break;


        }
        if (in < 1 || in > 3)
            cout << "Invalid input\n" << endl;
    }

}