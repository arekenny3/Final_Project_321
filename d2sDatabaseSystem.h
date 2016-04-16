#ifndef D@SDATABASE
#define D@SDATABASE
#include <iostream>
#include <string>
#include <fstream> // needed for the database
#include <windows.h>
#include "Users.h"
#include "tutorial.h"
#include "tinyxml2.h"
void d2sDatabaseSystem();
void databaseWelcomeMessage();
int databaseOptions();
void databaseWrite();
void databaseRead();
void databaseSearch();
int selectDatabase();
void makeUser();
int makeUserMenu();

void d2sDatabaseSystem()
{
	bool exit = false;
	int choice = 0;

	databaseWelcomeMessage();

	while (!exit)
	{
		while (!(choice = databaseOptions()) || (choice > 4 || choice < 1))
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
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		while (!(choice = selectDatabase()) || (choice > 4 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: makeUser();
			break;
		case 2: // createJobListingMenu();
			break;
		case 3: // createExamMenu();
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}
int selectDatabase()
{
	int x = 0;
	cout << "\n\n\tYour Options Are:"
		<< "\n\t1. User Database"
		<< "\n\t2. Job Listing Database"
		<< "\n\t3. Exam Database"
		<< "\n\t4. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}
void makeUser()
{
	Admin adm(" ", " ", " ", " ");
	User * newUser = new User;
	string id, name, username, password;
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		cout << "\n\n\tEnter an id: ";
		getline(cin, id);
		cout << "\n\tEnter a name: ";
		getline(cin, name);
		cout << "\n\tEnter a username: ";
		getline(cin, username);
		cout << "\n\tEnter a password: ";
		getline(cin, password);

		cout << "\n\n\tYou Entered: "
			<< "\n\t\tID: " << id
			<< "\n\t\tName: " << name
			<< "\n\t\tUsername: " << username
			<< "\n\t\tPassword: " << password
			<< "\n\n\tIs This Correct(1=T,0=F)?";
		cin >> choice;
		if (choice)
		{
			exit = true;
			adm.createUser(newUser, id, name, username, password);
			adm.storeToDatabase("UserDatabase.xml", newUser);
		}
		else
			errorWarning("Admin Typed In User Wrong. Try Again.");
	}

	delete newUser;
	newUser = 0;

	/* there is not that much error checking going on here,
	maybe because we trust the admin to know what he is doing */
}
void databaseRead()
{
}
void databaseSearch()
{
}
#endif
