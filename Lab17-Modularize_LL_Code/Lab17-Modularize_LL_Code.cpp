#include <iostream>
using namespace std;
const int SIZE = 7;
struct Node {
	float value;
	Node* next;
};
void output(Node*);

void addNodeFront(Node *& n){

	for (int i = 0; i < SIZE; i++) {
		int tmp_val = rand() % 100;
		
		Node* newVal = new Node;
		// adds node at head
		if (!n) {
			n = newVal;
			newVal->next = nullptr;
			newVal->value = tmp_val;
		}
		else {
			newVal->next = n;
			newVal->value = tmp_val;
			n = newVal;
		}
	}

	//output(n);
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

	cout << "After which node to insert 10000? " << endl;
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
	newnode->value = 10000;
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

	n = nullptr;
}

int main() {
	
	Node* head = nullptr;
	Node* current = nullptr;
	
	int count = 0;
	/* create a linked list of size SIZE with random numbers 0 - 99
	for (int i = 0; i < SIZE; i++) {
		int tmp_val = rand() % 100;
		Node* newVal = new Node;
		// adds node at head
		if (!head) {
			head = newVal;
			newVal->next = nullptr;
			newVal->value = tmp_val;
		}
		else {
			newVal->next = head;
			newVal->value = tmp_val;
			head = newVal;
		}
	}
	*/
	
	
	addNodeFront(head);
	output(head);
	
	
	
	/* deleting a node
	cout << "Which node to delete? " << endl;
	output(head);
	int entry;
	cout << "Choice --> ";
	cin >> entry;
	// traverse that many times and delete that node
	Node* current = head;
	Node* prev = nullptr; // start prev as nullptr to detect head deletion
	for (int i = 0; i < (entry - 1); i++) {
		prev = current;
		current = current->next;
	}
	// at this point, delete current and reroute pointers
	if (current) {
		if (prev == nullptr) {
			// deleting the head node
			head = current->next;
		}
		else {
			prev->next = current->next;
		}
		delete current;
		current = nullptr;
	}
	*/
	
	deleteNode(head, current);
	output(head);
	
	/* insert a node
	cout << "After which node to insert 10000? " << endl;
	count = 1;
	current = head;
	while (current) {
		cout << "[" << count++ << "] " << current->value << endl;
		current = current->next;
	}
	cout << "Choice --> ";
	cin >> entry;
	current = head;
	prev = nullptr; // reset prev to nullptr for same reason
	for (int i = 0; i < entry; i++) {
		prev = current;
		current = current->next;
	}
	// at this point, insert a node between prev and current
	Node* newnode = new Node;
	newnode->value = 10000;
	newnode->next = current;
	if (prev == nullptr) {
		// inserting before the head
		head = newnode;
	}
	else {
		prev->next = newnode;
	}
	*/
	
	insertNode(head, current);
	output(head);
	
	// deleting the linked list
	//current = head;
	//while (current) {
	//	head = current->next;
	//	delete current;
	//	current = head;
	//}
	
	head = nullptr;
	output(head);
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