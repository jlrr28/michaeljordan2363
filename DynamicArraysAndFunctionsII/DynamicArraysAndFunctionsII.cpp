#include <string>
#include <iostream>
using namespace std;

string reverseArray() {

	return 0;

}

void displayArray() {

}

int main()
{
	const int SIZE = 5;
	string* dStr = nullptr;
	dStr = new string[SIZE];
	*dStr = "what", "when", "where", "how", "why";

	for (int i = 0; i < SIZE; i++)
		cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;
	cout << endl;
	dStr[1] = "when";
	dStr[2] = "when";
	dStr[3] = "when";
	dStr[4] = "when";

	for (int i = 0; i < SIZE; i++)
		cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;

	delete[] dStr;

}
