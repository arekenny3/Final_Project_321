#include <iostream>
#include <string> // add an IFNDEF section to this file
#include "Users.h"

using namespace std;

int main()
{
	/*
		this is just to show how you can make the administrator
	*/


	Admin administrator("A12345", "Nick Whetstone", "ratherB_a_wet_stone9696", "my name is nick");

	administrator.displayUserData(&administrator);

	/*
		the administrator can change other users data
	*/

	administrator.changeUserID(&administrator, "A00005");
	administrator.changeUserName(&administrator, "Kane Rodriguez");
	administrator.changeUserUsername(&administrator, "kaustez");
	administrator.changeUserPassword(&administrator, "whats a pointer");

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

	cout << '\n';

	administrator.displayUserData(&firstStudent);


	/*
		students and faculty can view their real name and username
	*/

	cout << '\n';

	firstStudent.displayUserData(&firstStudent);

	/*
		but they cannot access the data from other users
	*/

	cout << '\n';

	firstStudent.displayUserData(&administrator); // will display an error message


	cin.get(); // pause screen

	return 0;
}
