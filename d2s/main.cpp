#include <iostream>
#include <string>
#include <fstream> // needed for the database
#include <windows.h>
#include "Users.h"
#include "tutorial.h"
#include "tinyxml2.h"
#include  "d2sDatabaseSystem.h"
#include "UserLogin.h"
#pragma warning(disable:4996) // get rid of those nasty warnings

using namespace tinyxml2;

//Protoyped functions
void welcome();

using namespace std;

int main()
{
	//admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well

	welcome();

	User* newUser = new User; // Memory Leak? I made news all the way through.
	//newUser = getUser(); // go through the login and verification process. SHOULD NOT MOVE PAST THIS POINT IF THEY CAN'T LOGIN

	// this is where calebs menu function will go --- void d2sMainMenu(string type);
	
	d2sDatabaseSystem();

	cin.clear();
	delete newUser;
	newUser = 0;

	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWelcome to D2S (Desire To Schedule)";
}

/*
	requirements for the d2sMainMenu function:

	-selectively choose what options to give users, based on their types
	(HINT: This snippet below will store the usertype into 'type')

				string type = userType(newUser);
				(could be "student", "faculty, or "admin")
	
	-OptionsForAdmin
	  List Admin Options
	-OptionsForFaculty
	  List Faculty Options
	-OptionsForStudent
	  List Student Options

	BONUS:
		make some default options that would be available for anyone (potential future guests)
	
	*/
