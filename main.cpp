#include <iostream>
#include <string>
#include "Users.h"
#include <windows.h>

//Protoyped functions
void welcome();
void UseAndPass();

using namespace std;

void admin_tutorial();

int main()
{
	// admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well

	welcome();
	UseAndPass();

	cin.get(); // pause screen

	return 0;
}

// Administration tutorial here
void admin_tutorial()
{
	/*
	this is just to show how you can make the administrator
	*/


	Admin administrator("A12345", "Nick Whetstone", "ratherB_a_wet_stone9696", "my name is nick");

	cout << "\n\n\t Creating an Admin\n";

	administrator.displayUserData(&administrator);

	/*
	the administrator can change other users data
	*/

	administrator.changeUserID(&administrator, "A00005");
	administrator.changeUserName(&administrator, "Kane Rodriguez");
	administrator.changeUserUsername(&administrator, "kaustez");
	administrator.changeUserPassword(&administrator, "whats a pointer");

	cout << "\n\n\t Admin can modify the data of others (including himself)\n";

	cout << '\n';

	administrator.displayUserData(&administrator);


	/*
	the administrator can create users
	*/

	Student firstStudent;
	string id = "S12123";
	string name = "Caleb N.";
	string username = "youresocool";
	string password = "i like cats";

	administrator.createUser(&firstStudent, id, name, username, password);

	cout << "\n\n\t Admin can create users (here a student is created)\n";

	cout << '\n';

	administrator.displayUserData(&firstStudent);


	/*
	students and faculty can view their real name and username
	*/

	cout << "\n\n\t Students and Faculty can view their real name and username \n\t(here: the student views his details)\n";

	cout << '\n';

	firstStudent.displayUserData(&firstStudent);

	/*
	but they cannot access the data from other users
	*/

	cout << "\n\n\t Students and faculty cannot view the data of others \n\t(here: student tries to view admin)\n";

	cout << '\n';

	firstStudent.displayUserData(&administrator); // will display an error message

	/*
	users cannot modify themselves or anyone else
	*/

	cout << "\n\n\t Students and faculty cannot modify their data without admin permission \n\t(here: student tries modify his ID)\n";

	cout << '\n';

	firstStudent.setID();

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
