#include <iostream>
#include <random>
using namespace std;
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20, SIZE = 15;
int rngAGE();
int rng1to15();

class Goat {
private:
	int age;
	string name;
	string color;
	string nameArray[15] = { "Fi","Fy","Fo","Fum","Eenie" ,"Meenie","Minie","Mo","La","Di" ,"Da","Dum","Doo","Tasty","Day" };
	string colorArray[15] = { "Grey", "Greyer", "Greyest", "Black", "White", "Brown", "Burgundy", "Pink", "Cream", "Dark Brown", "Yellowish", "Stripes", "Polka Dots", "Rainbow", "Neon" };
public:
	//Constuctors
	Goat() {
		age = rngAGE();
		name = nameArray[rng1to15()];
		color = colorArray[rng1to15()];
	}
	Goat(int a, string n) { age = a; name = n; }

	//Setters
	string getName

	void print() {
		cout << "The goat, " << name << ", is " << age << " years old and is " << color << " colored." << endl;
	}
};


class DoublyLinkedList {
private:
	struct Node {
		Goat data;
		Node* prev;
		Node* next;
		Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
			data = val;
			prev = p;
			next = n;
		}
	};
	Node* head;
	Node* tail;
public:
	// constructor
	DoublyLinkedList() { head = nullptr; tail = nullptr; }
	void push_back(Goat value) {
		Node* newNode = new Node(value);
		if (!tail) // if there's no tail, the list is empty
			head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	void push_front(Goat value) {
		Node* newNode = new Node(value);
		if (!head) // if there's no head, the list is empty
			head = tail = newNode;
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void insert_after(Goat value, int position) {
		if (position < 0) {
			cout << "Position must be >= 0." << endl;
			return;
		}
		Node* newNode = new Node(value);
		if (!head) {
			head = tail = newNode;
			return;
		}
		Node* temp = head;
		for (int i = 0; i < position && temp; ++i)
			temp = temp->next;
		if (!temp) {
			cout << "Position exceeds list size. Node not inserted.\n";
			delete newNode;
			return;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next)
			temp->next->prev = newNode;
		else
			tail = newNode; // Inserting at the end
		temp->next = newNode;
	}
	
	/*
	void delete_node(int value) {
		if (!head) return; // Empty list
		Node* temp = head;
		while (temp && temp->data != value)
			temp = temp->next;
		if (!temp) return; // Value not found
		if (temp->prev) {
			temp->prev->next = temp->next;
		}
		else {
			head = temp->next; // Deleting the head
		}
		if (temp->next) {
			temp->next->prev = temp->prev;
		}
		else {
			tail = temp->prev; // Deleting the tail
		}
		delete temp;
	}
	*/
	
	
	void print() {
		Node* current = head;
		if (!current) return;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void print_reverse() {
		Node* current = tail;
		if (!current) return;
		while (current) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
	
	
	
	~DoublyLinkedList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};



// Driver program
int main() {
	DoublyLinkedList list;
	
	Goat goat1;
	goat1.print();

	Goat goat2;
	goat2.print();

	
	/*
	int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
	for (int i = 0; i < size; ++i)
		list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
	cout << "List forward: ";
	list.print();
	cout << "List backward: ";
	list.print_reverse();
	cout << "Deleting list, then trying to print.\n";
	list.~DoublyLinkedList();
	cout << "List forward: ";
	list.print();
	*/
	
	return 0;
}

int rngAGE() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(1, 20);
	double x = (randomN(gen));

	return x;
}

int rng1to15() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(0, 14);
	double x = (randomN(gen));

	return x;
}