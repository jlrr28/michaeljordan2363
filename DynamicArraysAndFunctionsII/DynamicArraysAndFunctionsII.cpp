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
	*dStr = ( "what", "when", "where", "how", "why" );
	


	for (int i = 0; i < SIZE; i++)
		cout << dStr[i] << "  " << &dStr[i] << endl;


	delete[] dStr;

}
