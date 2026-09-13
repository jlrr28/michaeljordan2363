#include <string>
#include <iostream>
using namespace std;

string* reverseArray(int s, string* dS) {
	string* reverse= nullptr;
	reverse = dS;
	for (int i = 0 ,x = s - 1; i < s; i++ , x--)	
		dS[i] = reverse[x];

	cout << "dS[] inside reverseArray function" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;

	cout << "reverse[] inside reverseArray function" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << reverse[i] << "  " << &dS[i] << endl;


	return dS;
	delete[]reverse;
}

void displayArray(int s, string* dS) {
	cout << "Outputting string" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;
}

int main()
{
	const int SIZE = 5;
	string* dStr = nullptr;
	dStr = new string[SIZE];
	dStr[0] = "what";
	dStr[1] = "when";
	dStr[2] = "where";
	dStr[3] = "how";
	dStr[4] = "why";

	cout << "initial" << endl;
	displayArray(SIZE, dStr);
	dStr = reverseArray(SIZE, dStr);
	cout << "first reverse" << endl;
	displayArray(SIZE, dStr);
	dStr = reverseArray(SIZE, dStr);
	cout << "second reverse" << endl;
	displayArray(SIZE, dStr);
	dStr = reverseArray(SIZE, dStr);
	cout << "third reverse" << endl;
	displayArray(SIZE, dStr);

	delete[] dStr;
	
}
