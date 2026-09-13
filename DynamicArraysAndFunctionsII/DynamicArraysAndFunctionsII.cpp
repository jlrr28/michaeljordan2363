#include <string>
#include <iostream>
using namespace std;

string reverseArray() {

	return 0;

}

void displayArray(int s, string* dS) {


	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;

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
	dStr[2] = "where";
	dStr[3] = "how";
	dStr[4] = "why";

	displayArray(SIZE, dStr);


	for (int i = 0; i < SIZE; i++)
		cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;


	delete[] dStr;

}
