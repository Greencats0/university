#include iostream

using namespace std;

int main()
{
	int day; month; year; input;
	bool answer;
	char letter;

	cout << "Would you like to begin the program?" << endl;
	cin << answer;

	if (answer = true)
		cout << "Enter day" << endl;
	cin >> day;
	cout << "Enter age" << endl;
	cin >> month;
	cout << "Enter year" << endl;
	cin >> year;

	cout << "Today's date is " << month << "-" < day << "-" << year << endl;

	cout << "Did you like this program? Enter 1 if yes or any other value if no" << endl;
	cin >> input;

	bool answer;
	bool success;

	if (0 < input < 2)
		success = true;

	return 0;
}