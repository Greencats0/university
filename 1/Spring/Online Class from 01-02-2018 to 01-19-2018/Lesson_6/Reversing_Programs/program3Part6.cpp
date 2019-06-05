#include <iostream>

using namespace std;

int main()

{
	
	const int numOfCountries = 5;
	string callingCode[numOfCountries] = { "1", "44", "94", "234", "55", "33" };
	string country[numOfCountries] = { "USA", "UK", "Sri Lanka", "Nigeria", "Brazil", "France" };
	numOfCountries = 6;
	string countryInput;
	cout << "Enter a name of a country and I will tell you its international code." << endl;
	cin >> countryInput;

	for (int i = 0; i < numOfCountries; i++)
	{
		if (callingCode[i] = countryInput) {
			cout << "Code: " << callingCode[i] << endl;
			
		else
			cout << "Country info not in our records; sorry" << endl;
		}

	}

	
	return 0;
}