#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"

using namespace std;

int main()
{
	int usrChoice;
	string contChoice = "y";
	while (contChoice == "y")
	{
		cout << "What would you like to do?" << endl;
		cout << "Make A Note | Get Tagged Notes | Get All Notes (1/2/3)" << endl;
		cin >> usrChoice;
		cout << "\n";
		switch (usrChoice)
		{
		case 1:
			usrWriteLine();
			break;
		case 2:
			searchFile();
			break;
		case 3:
			readFile();
			break;
		default:
			break;
		}
		cout << "Would you like to do anything else? (y/n)" << endl;
		getline(cin >> ws, contChoice);
		cout << "\n";
	}
}