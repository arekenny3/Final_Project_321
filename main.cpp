#include <iostream>
#include <string>
#include <fstream> // needed for the database
#include <windows.h>
#include "Users.h"
#include "tutorial.h"
#include "tinyxml2.h"
#include  "d2sDatabaseSystem.h"
#pragma warning(disable:4996) // get rid of those nasty warnings

using namespace tinyxml2;

//Protoyped functions
void welcome();
User* getUser();
User* login(); // both login and loginVerification might not be 'safe' and login is now platform dependent to windows.. consider changing in future
User* loginVerification(string, string);
using namespace std;

int main()
{
	//admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well
	//welcome();
	//User* newUser = new User;
	//newUser = getUser(); // go through the login and verification process. SHOULD NOT MOVE PAST THIS POINT IF THEY CAN'T LOGIN

	d2sDatabaseSystem();
	//Admin adm("A12345", "Nick Whetstone", "ratherB_a_wet_stone9696", "my name is nick");

	cin.clear();
	cin.ignore();
	cin.get();

	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWelcome to D2S (Desire To Schedule)";
}

User* getUser()
{
	User* newUser = NULL;

	while ((newUser = login()) == NULL)
	{
		errorWarning("Incorrect Username or Password");
	}

	return newUser;
}

User* login()
{
	string username;
	string password;

	cout << "\n\n\tEnter a username: ";
	cin >> username;
	cout << "\n\tEnter your password: ";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	getline(cin, password);
	cin >> password;


	/* Must turn screen ouput back on for user input */
	SetConsoleMode(hStdin, mode |= ENABLE_ECHO_INPUT);



	/*
	NOTE: This code is dependent on WINDOWS. Consider changing in future OR find a
	way to only include this on windows, and have separate methods for implementing on
	Mac, Linux, etc.
	*/
	return loginVerification(username, password);
}

User* loginVerification(string username, string password)
{
	// implement in future. For now: Return true
	cout << "\n\n\tYour Username: " << username
		<< "\n\n\tYour Password: " << password; // NOTE: For testing puposes only, delete later

	/*

	search database for the user matching this username and password
	If found and password matches, RETURN THE USER THAT WAS FOUND;
	ELSE If problems found RETURN NULL;
	*/

	return NULL;
}
