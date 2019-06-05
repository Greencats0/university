#include <iostream>

using namespace std;

int main()

{
	const int houses = 5;
	const int roomsPerHouse = 3;
	bool onOrOff;
	bool lights[houses][roomsPerHouse];
	cout << "We have " << houses + roomsPerHouse << " rooms in total!!" << endl;
	cout << "This program keeps track of whether lights are turned on in a certain room in a certain house" << endl;

	for (int i = 0; i < houses; i++)
	{
	        cout << "Are lights on in Room # " << i << " / House # 1 ?" << endl;
			cin >> lights[0][i];
	}
	for (int i = 1; i < houses; i++)
	{
		cout << "Are lights on in Room # " << i + 1 << " / House # 2 ?" << endl;
		cin >> lights[1][i];
	}
	for (int i = 0; i < houses; i++)
	{
		cout << "Are lights on in Room # " << i + 1 << " / House # 3 ?" << endl;
		cin >> lights[2][i];
	}
	return 0;
}