#include <iostream>
#include <string>
#include <windows.h>
#include "Users.h"
#include "tutorial.h"

//Protoyped functions
void welcome();
bool login(); // both login and loginVerification might not be 'safe' and login is now platform dependent to windows.. consider changing in future
bool loginVerification(string,string);

using namespace std;

int main()
{
	//admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well

	welcome();
	while (!login()) // was login successful?
	{
		cout << "\n\n\t--Error-- Incorrect Username or Password"; /* perhaps make separate function for error handling in main 
																  (NOTE: maybe implement try-catch later on */
	}

	cin.clear();
	cin.ignore();
	cin.get();

	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWelcome to D2S (Desire To Schedule)";
}

bool login()
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

bool loginVerification(string username, string password)
{
	// implement in future. For now: Return true
	cout << "\n\n\tYour Username: " << username
		<< "\n\n\tYour Password: " << password; // NOTE: For testing puposes only, delete later

	return true;
}
