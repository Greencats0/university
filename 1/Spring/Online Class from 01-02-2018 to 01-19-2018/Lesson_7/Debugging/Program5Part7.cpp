#include <iostream>

using namespace std;

int modifyValue(bool val); 

int main()
{
	int value;

	cout << "Enter a value" << endl;
	cin >> value;

	cout << "Ok, let's modify it" << endl << endl;

	value = modifyValue(value);

	cout << "New Value: " << value << endl;

	return 0;
}

int modifyValue(int val)
{
	int choice, num;

	cout << "Change value by: " << endl;
	cout << "1. Adding to it" << endl;
	cout << "2. Subtracting from it" << endl;
	cin >> choice;

	cout << "Modify by? Enter a num " << endl;
	cin >> num;

	if (choice = 1) 
		val += num;

	else if (choice == 2)
		val =- num; 

	return val; // Since we are only returning one val, what could have been changed in the function header? 
}