#include <iostream>
using namespace std;
const int SIZE = 7;

struct Node {
	float value;
	Node* next;
};
void output(Node*);

void addNodeFront(Node *& n){
	float tmp = 0;
	cout << "Enter data to be added to front of the list: ";
	cin >> tmp; cout << endl;
	cout << "adding " << tmp << " to front of list." << endl;
	Node* newVal = new Node;

	// adds node at head
	if (!n) {
		n = newVal;
		newVal->next = nullptr;
		newVal->value = tmp;
	}
	else {
		newVal->next = n;
		newVal->value = tmp;
		n = newVal;
		}
	
}

void addNodeBack(Node* &n, Node* &c) {
	float tmp = 0;
	Node* lastNode = nullptr;
	
	cout << "Enter data to be added to back of the list :" ;
	cin >> tmp; cout << endl;
	cout << "adding " << tmp << " to  back of list." << endl;
	
	c = n;
	Node* newVal = new Node;
		// adds node at back
		if (!n) {
			n = newVal;
			newVal->next = nullptr;
			newVal->value = tmp;
		}
		else {
			while (c) {
				lastNode = c;
				c = c->next;
			}			
			lastNode->next = newVal;
			newVal->next = nullptr;
			newVal->value = tmp;

		}

}

void deleteNode(Node* &n, Node* &c) {
	// deleting a node
	cout << "Which node to delete? " << endl;
	output(n);
	int entry;
	cout << "Choice --> ";
	cin >> entry;
	// traverse that many times and delete that node
	c = n;
	Node* prev = nullptr; // start prev as nullptr to detect head deletion
	for (int i = 0; i < (entry - 1); i++) {
		prev = c;
		c = c->next;
	}
	// at this point, delete current and reroute pointers
	if (c) {
		if (prev == nullptr) {
			// deleting the head node
			n = c->next;
		}
		else {
			prev->next = c->next;
		} 
		cout << "deleting" << c->next << endl;
		delete c;
		c = nullptr;
	}

	output(n);

	//return n;
}

void insertNode(Node*& n, Node*& c) {
	float tmp = 0;
	cout << "What data will be inserted?: ";
	cin >> tmp;
	cout << "After which node to insert " << tmp << "?: " << endl;
	int count = 1;
	c = n;
	Node* prev = nullptr;
	while (c) {
		cout << "[" << count++ << "] " << c->value << endl;
		c = c->next;
	}
	cout << "Choice --> ";
	int entry;
	cin >> entry;
	c = n;
	prev = nullptr; // reset prev to nullptr for same reason
	for (int i = 0; i < entry; i++) {
		prev = c;
		c = c->next;
	}
	// at this point, insert a node between prev and current
	Node* newnode = new Node;
	newnode->value = tmp;
	newnode->next = c;
	if (prev == nullptr) {
		// inserting before the head
		n = newnode;
	}
	else {
		prev->next = newnode;
	}

}

void deleteList(Node*& n, Node*& c) {
	cout << "deleting the linked list" << endl;
	c = n;
	while (c) {
	n = c->next;
	delete c;
	c = n;
}
	c = nullptr;
	n = nullptr;
}

int main() {
	
	Node* head = nullptr;
	Node* current = nullptr;

	char input = ' ';
	while (input != 'q') {
		cout << "--------------------------------------------------------------" << endl;
		cout << "Pick an option:\n" << "Add node to front: f\n" << "Add node to back: b\n"
			<< "Delete node: d\n" << "Insert node: i\n" << "Print list: p\n"
			<< "Delete the list: D\n" << "Quit: q" << endl;
		
		cin >> input;
		
		switch (input) {
		case 'f':
			addNodeFront(head);
			break;
		case 'b':
			addNodeBack(head,current);
			break;
		case 'd':
			deleteNode(head, current);
			break;
		case 'i':
			insertNode(head, current);
			break;
		case 'p':
			output(head);
			break;
		case 'D':
			deleteList(head, current);
		default: break;

		}




	}


	/*
	addNodeFront(head);
	output(head);
	
	deleteNode(head, current);
	output(head);

	addNodeBack(head, current);
	output(head);

	
	insertNode(head, current);
	output(head);
	
	deleteList(head, current);
	output(head);
	
	addNodeBack(head, current);
	addNodeBack(head, current);
	addNodeBack(head, current);
	
	output(head);
	*/


	return 0;
}

void output(Node* hd) {
	if (!hd) {
		cout << "Empty list.\n";
		return;
	}
	int count = 1;
	Node* current = hd;
	while (current) {
		cout << "[" << count++ << "] " << current->value << "  data address: " << &current ->value << " pointer address: " << &current << endl;
		current = current->next;
	}
	cout << endl;
}