#include <iostream>
#include <string>

using namespace std;

void deliverMessage(string message)
{
	cout << "Message Delivered to function: " << message << endl;
}

string getMessage()
{
	return "How are you?";
}

int main()
{
	bool repeat = true;

	cout << "Let's deliver a message" << endl;

	while (repeat = true) 
	{
		cin.clear();
		deliverMessage("Hi!!!");
		cout << "Would you like to deliver the message again? " << endl;
		cin >> repeat;
	}

	cout << "Now, lets receive a message" << endl;
	string message = getMessage();

	cout << "Message Received in main: " << message << endl;

	return 0;
}