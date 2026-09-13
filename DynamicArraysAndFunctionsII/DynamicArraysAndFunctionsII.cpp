#include <string>
#include <iostream>
using namespace std;

string* reverseArray(int s, string* dS) {

	string* reverse= nullptr;
	reverse = new string[s];
	cout << "Reversing this string";
	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;

	return reverse;

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

	//displayArray(SIZE, dStr);
	reverseArray(SIZE, dStr);

	delete[] dStr;
	
	//for (int i = 0; i < SIZE; i++)
		//cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;

}
