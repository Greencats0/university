#include <iostream>

using namespace std;

int main()
{

	const int size;
	size = 3;

	int midterm1Scores[size];
	int midterm2Scores[size] = { 100, 98, 97 };

	midterm1Scores = { 100, 87, 97};

	if (midterm1Scores[0] == midterm2Scores[0] && midterm1Scores[1] == midterm2Scores[1] && midterm1Scores[2] == midterm2Scores[2])
		cout << "Wow! Scores are exactly the same for both midterms" << endl;

	cout << "Midterm 1 Scores" << endl;
	for (int i = 0; i <= 3; i++)
		cout << midterm1Scores[i];
	
	cout << "Midterm 2 Scores" << endl;
	for (int i = 0; i <= 3; i++)
		cout << midterm1Scores[i];

	return 0;
}