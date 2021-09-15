#pragma warning(disable : 4996)
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>

#include "functions.h"

using namespace std;

void usrWriteLine()
{
	ofstream GoogleHome("GoogleHome.txt", ios::app);
	string msg;
	string msgType;
	int usrWriteTypeChoice;
	cout << "Choose Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrWriteTypeChoice;
	cout << "Type what you want me to remember" << endl;
	string usrstr;
	getline(cin >> ws, usrstr);
	cout << "\n";
	time_t timetoday;
	time(&timetoday);
	string currentTime = asctime(localtime(&timetoday));

	switch (usrWriteTypeChoice)
	{
	case 1:
		msg = "REMINDER: " + usrstr + " -" + currentTime;
		GoogleHome << msg << endl;
		break;
	case 2:
		msg = "MESSAGE: " + usrstr + " -" + currentTime;
		GoogleHome << msg << endl;
		break;
	case 3:
		msg = "SCHEDULE: " + usrstr + " -" + currentTime;
		GoogleHome << msg << endl;
		break;
	case 4:
		msg = "ALARM: " + usrstr + " -" + currentTime;
		GoogleHome << msg << endl;
		break;
	default:
		break;
	}

	cout << "SAVED- " + msg << endl;
}

void searchFile()
{
	ifstream GoogleHomeRead("GoogleHome.txt");
	int usrTypeChoice;
	cout << "What type of item would you like to search?" << endl;
	cout << "Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrTypeChoice;
	cout << "\n";
	string type;
	switch (usrTypeChoice)
	{
	case 1:
		type = "REMINDER:";
		break;
	case 2:
		type = "MESSAGE:";
		break;
	case 3:
		type = "SCHEDULE:";
		break;
	case 4:
		type = "ALARM:";
		break;
	default:
		break;
	}

	string line;
	while (getline(GoogleHomeRead, line))
	{
		if (line.find(type) != string::npos) {
			cout << line << endl;
			cout << "\n";
		}
	}
	cout << "\n";
}

void readFile()
{
	ifstream GoogleHomeRead("GoogleHome.txt");
	string line;
	while (getline(GoogleHomeRead, line)) {
		cout << line << endl;
	}
}