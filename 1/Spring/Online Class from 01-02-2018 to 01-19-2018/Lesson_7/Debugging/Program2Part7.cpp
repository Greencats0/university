#include <iostream>

using namespace std;

int findSum(int num1, num2)

int main()
{
	int first, second;

	cout << "Enter two integers and I will find the sum" << endl;
	cin >> first;
	cin >> second;

	findSum(int first, int second);

	return 0;
}


int findSum(int num1, int num2)
{
	bool response = false;
	int total = num1 + num2;

	do
	{
		cout << "Sum of " << num1 << " and " << num2 << " is " << total << endl;

		cout << "Do you want to display result again? (1 for YES; 0 for NO)" << endl;
		cin >> response;
	}

	while (response == true)

		return total, num1, num2;

	cout << "Thank you" << endl;
}