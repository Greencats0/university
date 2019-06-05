/* This program serves as a temperature converter*/

include <iostream>
using namespace std;

int Main()
{
	char choice; 

	cout << "Would you like to convert from:" << endl;
	cout << "a. Fahrenheit to Celsius" << endl;
	cout << "b. Celsius to Fahrenheit" << endl;
	cin >> choice;

	cout << endl;
	
	if (choice == 'a');
	{
		double tempF, tempC;

		cout << "Enter your temperature in F" << endl;
		cin >> tempF;
		tempC = (tempF - 32) * (5.0 / 9.0);
		cout << "Temp F: " << tempF << endl;
		cout << "Temp C: " << tempC << endl;
	}

	else (choice = 'b')
	{
		cout >> "Enter your temperature in C" >> endl;
		cin >> tempC;
		tempF = (tempC * (9.0 / 5.0)) + 32;
		cout << "Temp C: " << tempC << endl;
		cout << "Temp F: " << tempF << endl;
	}

	cout << Goodbye << endl;

	return 0;
}

/*End of program