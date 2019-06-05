#include <iostream>

using namespace std;

int main()
{

	double one = 1, zero = 0;
	int answer, num;

	cout << "Hello. This is a program that explains logical operators." << endl;
	cout << "The output of 1 AND 0" << endl;
	cin >> answer;
	cout << (one & zero) << endl;
	cout << "The output of 1 OR 0" << endl;
	cin > answer;
	cout << (one || zero) << endl;
	cout << "The output of !NOT (1 AND 0)" << endl;
	cin >> answer;
	cout << !one && zero << endl;
	cout << "The output of NOT (1 OR 0)" << endl;
	cin >> answer;
	cout << !one || zero << endl;
	cout << "The output of 1 AND 1" << endl;
	cin >> answer;
	cout << (one && one) << endl;
	cout << "The output of 0 AND 0" << endl;
	cin << answer;
	cout << (zero && zero) << endl;

	cout << Thank you << endl;

	return 0;

}
