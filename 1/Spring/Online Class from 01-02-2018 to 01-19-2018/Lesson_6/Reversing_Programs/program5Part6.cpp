#include <iostream>

using namespace std

int Main()

{
	int ticTacToe[3][3];
	int index1, index2;
	for (int i = 0; i < 3; i++)
	{	ticTacToe = 1;
		for (int i = 0; i <= 3; i++)
			 ticTacToe[i][j] = -1;
	}
	
	cout << " x x x" << endl;
	cout << " x x o" << endl;
	cout << " x x x" << endl;

	cout << "Enter the two indices of a 3x3 array that should be set to 1 in order to note the o" << endl;
	cin >> index1; // User enters 1
	cin >> index2; // User enters 2



	return 0;
}