#ifndef USERLOGIN
#define USERLOGIN
#include <iostream>
#include <string>
#include <windows.h>
#include "Users.h"

User* getUser();
User* login(); // both login and loginVerification might not be 'safe' and login is now platform dependent to windows.. consider changing in future

User* getUser()
{
	User* newUser = NULL;

	while ((newUser = login()) == NULL)
	{
		errorWarning("Incorrect Username or Password");
	}
	cout << "\n\n\n\n\t\tLogin Successful: Welcome, " << newUser->getUsername();

	return newUser;
}

User* login()
{
	string username;
	string password;

	cout << "\n\n\tEnter a username: ";
	getline(cin, username);
	cout << "\n\tEnter your password: ";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	getline(cin, password);
	/* Must turn screen ouput back on for user input */
	SetConsoleMode(hStdin, mode |= ENABLE_ECHO_INPUT);



	/*
	NOTE: This code is dependent on WINDOWS. Consider changing in future OR find a
	way to only include this on windows, and have separate methods for implementing on
	Mac, Linux, etc.
	*/
	return verifyLogin(username,password);
}

#endif
