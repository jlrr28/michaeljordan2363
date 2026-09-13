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
	*dStr = ("what", "when", "where", "how", "why");
	dStr[1] = "what";


	for (int i = 0; i < SIZE; i++)
		cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;


	delete[] dStr;

}
