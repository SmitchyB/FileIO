#pragma warning(disable : 4996)
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>

#include "functions.h"

using namespace std;

void usrWriteLine()  //Creates file if it doesnt exist and allows user to make entry
{
	ofstream GovernmentSpyDevice("GovernmentSpyDevice.txt", ios::app); //appends at the end of the file
	string msg;
	string msgType;
	int usrWriteTypeChoice;
	cout << "Choose Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrWriteTypeChoice; //users choice
	string usrstr;
	getline(cin >> ws, usrstr); //entry
	cout << "\n";
	time_t timetoday; //make time_t object
	time(&timetoday); //getting the time
	string currentTime = asctime(localtime(&timetoday)); //formats the time

	switch (usrWriteTypeChoice) //switch statement for the different options for functionality
	{
	case 1: //reminder case
		msg = "The Government will remember to tell you: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 2: //message case
		msg = "The Government will tell you: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 3: //schedule case
		msg = "The Government will add this to your schedule: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 4: //alarm case
		msg = "The Government will tell you it is time for: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	default:
		break;
	}

	cout << "SAVED- " + msg << endl;

}

void searchFile() //searching for a tag
{
	ifstream GovernmentSpyDeviceRead("GovernmentSpyDevice.txt");
	int usrTypeChoice;
	cout << "What type of item would you like to search?" << endl;
	cout << "Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrTypeChoice;
	cout << "\n";
	string type;
	switch (usrTypeChoice) //switch statement to find the specific tag the user chose
	{
	case 1: //reminder tag
		type = "REMINDER:";
		cout << "This is what the goverment remembers you said.";
		break;
	case 2: //message tag
		type = "The government told me to tell you:";
		break;
	case 3: //schedule tag
		type = "SCHEDULE:";
		cout << "The government always knows what youre doing at all times!";
		break;
	case 4: //alarm tag
		type = "The government is telling you its time!:";
		break;
	default:
		break;
	}

	string line;
	while (getline(GovernmentSpyDeviceRead, line)) //searches through the files line by line
	{
		if (line.find(type) != string::npos) { //if type exist in line then print line
			cout << line << endl;
			cout << "\n";
		}
	}
	cout << "\n";
}

void readFile() //read entire file
{
	ifstream GovernmentSpyDeviceRead("GovernmentSpyDevice.txt");
	string line;
	while (getline(GovernmentSpyDeviceRead, line)) { //printing line by line of the file
		cout << line << endl;
	}
}