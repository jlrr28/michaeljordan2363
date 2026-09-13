#include <string>
#include <iostream>
using namespace std;

string* reverseArray(int s, string* dS) {
	string* reverse= nullptr;
	reverse = new string[s];

	for (int i = 0 ,x = s - 1; i < s; i++ , x--)	
		reverse[x] = dS[i];
	
	return reverse;
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

	displayArray(SIZE, dStr);
	dStr = reverseArray(SIZE, dStr);
	displayArray(SIZE, dStr);

	delete[] dStr;
	
	for (int i = 0; i < SIZE; i++)
		cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;

}
