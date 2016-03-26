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

			this is meant to show you guys polymorphism 

	
	User firstUser("A12345", "Nick Whetstone", "ratherB_a_wet_stone9696", "my name is nick");
	Admin firstAdmin; 
	User *pfirstAdmin = &firstAdmin;

	*pfirstAdmin = firstUser;

	cout << firstAdmin.itsID;

*/

	cin.get(); // pause screen

	return 0;
}
