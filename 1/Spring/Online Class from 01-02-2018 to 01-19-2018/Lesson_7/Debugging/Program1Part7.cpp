#include <iostream>
using namespace std;

// What is missing here?

int num;

int func1()
{
	cout << "Hello from func1" << endl;
	num = func2();
	// What is missing here?
}

int main()
{
	cout << "Hello from main" << endl;
	func1();
	func2();
	cout << "Bye" << endl;

	return 0;
}

void func2()
{
	string msg;
	cout << "Hello from func2" << endl;
}
