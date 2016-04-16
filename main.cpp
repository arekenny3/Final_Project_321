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

	User* newUser = new User;
	//newUser = getUser(); // go through the login and verification process. SHOULD NOT MOVE PAST THIS POINT IF THEY CAN'T LOGIN

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
