#include <string>
#include <iostream>
using namespace std;

string* reverseArray(int s, string* dS) {

	string* reverse= nullptr;
	reverse = new string[s];
	cout << "Reversing this string" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;
	
	for (int i = s; i > 0; i--)
	{
		cout << i;
		int x = 0;
		reverse[x] = dS[i-1];
		x++;
		
	}

	//cout << "reverse result" << endl;
	//for (int i = 0; i < s; i++)
		//cout << i << " " << dS[i] << "  " << &dS[i] << endl;

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
	dStr = reverseArray(SIZE, dStr);
	//displayArray(SIZE, dStr);

	delete[] dStr;
	
	//for (int i = 0; i < SIZE; i++)
		//cout << i << " " << dStr[i] << "  " << &dStr[i] << endl;

}
