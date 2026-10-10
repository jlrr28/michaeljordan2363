// COMSC - 210 || Lab 21 || Jose Luis Ramos
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
	int getAge()		{ return age; }
	string getName()	{ return name; }
	string getColor()	{ return color; }

	//Methods
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
	
	void print() {
		cout << "Forward: " << endl;
		Node* current = head;
		if (!current) {
			cout << "List empty!" << endl;
			return;
		}
			while (current) {
			cout << "    " << current->data.getName()
			<< " (" << current->data.getColor()
			<< ", " << current->data.getAge() << ")" << endl;
			current = current->next;
		}
		cout << endl;
	}
	void print_reverse() {
		cout << "Backward: " << endl;
		Node* current = tail;
		if (!current) {
			cout << "List empty!" << endl;
			return;
		}
		while (current) {
			cout << "    " << current->data.getName()
			<< " (" << current->data.getColor()
			<< ", " << current->data.getAge() << ")" << endl;
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
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(5, 20);
	
	list.print();
	list.print_reverse();
	
	int x = randomN(gen);
	cout << "Generating " << x << " goats, pushing into list from the front." << endl;
	for (int i = 0; i < x; i++) {
		Goat goat1;
		list.push_back(goat1);
	}

	list.print();
	list.print_reverse();
	
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