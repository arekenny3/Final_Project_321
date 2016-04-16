#include <iostream>
#include <string>
#include <fstream> // needed for the database
#include <windows.h>
#include "Users.h"
#include "tutorial.h"
#include "tinyxml2.h"

#pragma warning(disable:4996) // get rid of those nasty warnings

using namespace tinyxml2;

//Protoyped functions
void welcome();
User* getUser();
User* login(); // both login and loginVerification might not be 'safe' and login is now platform dependent to windows.. consider changing in future
User* loginVerification(string, string);
void errorWarning(char* s)
{
	cout << "\n\n\t--Error-- " << s;
}
using namespace std;

void d2sDatabaseSystem();
void databaseWelcomeMessage();
int databaseOptions();
void databaseWrite();
void databaseRead();
void databaseSearch();

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

void d2sDatabaseSystem()
{
	bool exit = false;
	int choice = 0;

	databaseWelcomeMessage();

	while (!exit)
	{
		while (!(choice = databaseOptions()) || (choice > 4 || choice < 1) )
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: databaseWrite();
			break;
		case 2: // do something
			break;
		case 3: // do something
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}

void databaseWelcomeMessage()
{
	cout << "\n\n\t\tWelcome to the D2S Database Management System";
}

int databaseOptions()
{
	int x = 0;
	cout << "\n\n\tYour Options Are:"
		<< "\n\t1. Write to Database"
		<< "\n\t2. Read from Database"
		<< "\n\t3. Search Database"
		<< "\n\t4. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}

void databaseWrite()
{
	Admin adm;
	User *newUser = new User; // make sure to deallocate
	adm.createUser(newUser,"S12123", "Caleb N.", "youresocool", "i like cats");

	adm.storeToUserDatabase(newUser);

	delete newUser;
	newUser = 0;

}
void databaseRead()
{
}
void databaseSearch()
{
}
