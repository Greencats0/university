#include <iostream>

using namespace std;

int sandwichPrice = 2; // What could these 2 variables have been? 
int drinkPrice = 1;	// What could these 2 variables have been?

int calculateTotal(int sandwiches, drinks) 
{
	int total;

	total = (sandwiches * sandwichPrice) + (drinks * drinkPrice);

	return total; cout << "Total has been returned. " << endl;
}

int main()
{
	int item1, item2
		
	double balance; 

	cout << "Hello. Here is your menu." << endl;
	cout << "1. Sandwiches --- $ " << sandwichPrice << endl;
	
	cout << "2. Drinks     --- $ " << drinkPrice << endl;
	cout << "How many sandwiches would you like?" << endl;
	cin >> item1;
	cout << "What about drinks?" << endl;
	cin >> item2;

	balance = calculateTotal(int item1, int item2); 

	cout << "Total payment due is $ " << balance << endl;

	cout << "Thank you." << endl;

	return 0;
}