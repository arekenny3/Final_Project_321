#include <iostream>
#include <string>
#include <windows.h>
#include "Users.h"
#include "tutorial.h"

//Protoyped functions
void welcome();
void UseAndPass();

using namespace std;

int main()
{
	//admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well

	welcome();
	UseAndPass();

	cin.get(); // pause screen

	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWelcome to D2S (Desire To Schedule)";
}

void UseAndPass()
{
	string username;
	string password ;

	cout << "\n\n\tEnter a username: ";
	cin >> username;
	cout << "\n\tEnter your password: ";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	getline(cin, password);
	cin >> password;
}
