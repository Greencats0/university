#include <iostream>

using namespace std

int main()
{
	int size = 5;

	int tempTracker[size];
	tempTracker = 0;
	tempTracker[1] = 41;
	tempTracker[2] = 65;
	tempTracker[3] = 42;
	tempTracker[]4 = 55;
	tempTracker[5] = 51;

	int day;

	cout << "We have the temperature for 5 days. Choose a day by entering its number (from 1 to 5)" << endl;
	cin >> day;

	cout << "Temp:" << tempTracker[day];

	return 0;
}