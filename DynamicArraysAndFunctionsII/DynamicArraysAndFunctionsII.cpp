#include <string>
#include <iostream>
using namespace std;

void reverseArray(int s, string* dS) {
	string* reverse= nullptr;
	reverse = new string[s];
	//string reverse[s];
	for (int i = 0 ,x = s - 1; i < s; i++ , x--)	
		dS[i] = reverse[x];
	
	/* Leaving this here for future reference for myself, 
	cout << "dS[] inside reverseArray function" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << dS[i] << "  " << &dS[i] << endl;

	cout << "reverse[] inside reverseArray function" << endl;
	for (int i = 0; i < s; i++)
		cout << i << " " << reverse[i] << "  " << &reverse[i] << endl;*/

	//return reverse;
	delete[]reverse;
	//delete[]dS; // Not sure if necessary, leaving it here to be safe
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
	reverseArray(SIZE, dStr);
	displayArray(SIZE, dStr);

	delete[] dStr;
	

}
