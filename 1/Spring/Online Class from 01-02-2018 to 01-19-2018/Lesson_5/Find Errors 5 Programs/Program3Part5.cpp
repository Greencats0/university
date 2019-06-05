#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double area = 0.0;
	bool repeat = true;
	int count = 0.0; int bonus 2.0;

	while (repeat = true)
	{
		if (!(count == 10) || (count < 0) && (count > 10))
		{

			char choice;
			cout << endl << "Hello. Welcome to your personal math assistant..." << endl << endl;
			cout << "Please make a selection." << endl;
			cout << "a. Area of a square" << endl;
			cout << "b. Area of a triangle" << endl;
			cout << "c. Area of a circle" << endl;
			cin >> choice;

			switch (choice)
			{

			case a:
				double s;
				cout << "Enter value of side:" << endl;
				cin >> s;
				area = pow(s, 2);
				break;

			case 'b':
				double b, h;
				cout << "Enter value of base:" << endl;
				cin >> b;
				cout << "Enter value of height:" << endl;
				cin >> h;
				area = (b*h) * 0.5;

			case 'c':
				double r;
				cout << "Enter value of radius:" << endl;
				cin >> r;
				area = 3.14 * pow(r, 2);
				break;

			default:
				cout << "Invalid choice:" << endl;

			}

			cout << endl << "Area: " << area << endl;
			cout << endl << "Would you like to repeat? Enter 1 for YES; 0 for NO" << endl;
			cin >> repeat;

			(count-bonus)++;
		}

		else
		{
			cout << "You have used this tool over 10 times day. Try again tomorrow." << endl;
			repeat = false;
		}

	}
	cout << "Did you like this program?" << endl;
	cin >> response;

	// End of program return 0;
}
