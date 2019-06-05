#include iostream

using namespace std;

int main 
{
	int num1, num2;
	string name;

	cout << "Hello, enter your name:\n";
	cin >> name;

	cout << "Welcome " << name << "!\n";

	cout << "Enter 2 numbers and I will add them.\n;"
	cout << "Enter the first number:\n";
	cin >> num1;
	cout << "Enter the second number:\n";
	cin >> num2;
	cout << num1 + num2;
	cout << endl;

	cout << "Enter 2 numbers and I will subtract them.\n";
	cin >> num1;
	cout << "Enter the second number:\n";
	cin >> num2;
	cout << num1 - num2;
	cout << endl;

	cout << "Enter 2 numbers and I will multiply them.\n";
	cin >> num1;
	cout << "Enter the second number:/n";
	cin >> num2;
	cout << num1 * num2;
	cout << endl;

	cout << "Enter 2 numbers and I will divide them.\n";
	cin >> num1;
	cout << "Enter the second number\n";
	cin >> num2;
	cout << num1 / num2;
	cout << endl;

	string name;

	cout << "Thank you " << name << "!\n";
	return 0;

}