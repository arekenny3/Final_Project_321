#ifndef D2SDATABASE
#define D2SDATABASE
#include <iostream>
#include <string>
#include <windows.h>
#include "Users.h"
#include "tutorial.h"
#include "tinyxml2.h"
#include <deque>

using namespace std;

void d2sDatabaseSystem();
void databaseWelcomeMessage();
int databaseOptions();
void databaseWrite();
void databaseRead();
void databaseSearch();
int selectDatabase(string s);
void makeUser();
void readUsers();
int makeUserMenu();
User* searchUserDatabase(char *, string, bool);
void searchUsers(bool);
int chooseUserSearchAttribute();
string chooseUserSearchKey(string);
void databaseRemove();

void d2sDatabaseSystem()
{
	bool exit = false;
	int choice = 0;

	databaseWelcomeMessage();

	while (!exit)
	{
		while (!(choice = databaseOptions()) || (choice > 5 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: databaseWrite();
			break;
		case 2: databaseRead();
			break;
		case 3: databaseSearch();
			break;
		case 4: databaseRemove();
			break;
		case 5: exit = true;
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
	cout << "\n\n\tDatabase Options:"
		<< "\n\t1. Write to Database"
		<< "\n\t2. Read from Database"
		<< "\n\t3. Search Database"
		<< "\n\t4. Remove from Database"
		<< "\n\t5. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}

void databaseWrite()
{
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		while (!(choice = selectDatabase("to Write to")) || (choice > 4 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: makeUser();
			break;
		case 2: errorWarning("Functionality Not Yet Offered");// createJobListingMenu();
			break;
		case 3: errorWarning("Functionality Not Yet Offered"); // createExamMenu();
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}
void databaseRead()
{
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		while (!(choice = selectDatabase("to Read to")) || (choice > 4 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: readUsers();
			break;
		case 2: errorWarning("Functionality Not Yet Offered");// createJobListingMenu();
			break;
		case 3: errorWarning("Functionality Not Yet Offered");// createExamMenu();
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}
void databaseSearch()
{
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		while (!(choice = selectDatabase("to Search")) || (choice > 4 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1:	searchUsers(false);
			break;
		case 2: errorWarning("Functionality Not Yet Offered");// createJobListingMenu();
			break;
		case 3: errorWarning("Functionality Not Yet Offered");// createExamMenu();
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}
void databaseRemove()
{
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		while (!(choice = selectDatabase("to Remove from")) || (choice > 4 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1:	searchUsers(true);
			break;
		case 2: errorWarning("Functionality Not Yet Offered");// createJobListingMenu();
			break;
		case 3: errorWarning("Functionality Not Yet Offered");// createExamMenu();
			break;
		case 4: exit = true;
			break;
		default: // do something
			break;
		}
	}
}
int selectDatabase(string s)
{
	int x = 0;
	cout << "\n\n\tSelect a Database " << s << ":"
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
	bool exit = false,
		correct = false;
	int choice = 0;
	while (!exit)
	{
			cout << "\n\n\tEnter an id: ";
			getline(std::cin, id);
			cout << "\n\tEnter a name: ";
			getline(std::cin, name);
			cout << "\n\tEnter a username: ";
			getline(std::cin, username);
			cout << "\n\tEnter a password: ";
			getline(std::cin, password);
			while (!correct)
			{
				correct = false;
				cout << "\n\n\tYou Entered: "
					<< "\n\t\tID: " << id
					<< "\n\t\tName: " << name
					<< "\n\t\tUsername: " << username
					<< "\n\t\tPassword: " << password
					<< "\n\n\tIs This Correct(1=T,0=F)?";
				std::cin >> choice;
				std::cin.clear();
				std::cin.ignore();
				if (choice < 0 || choice > 2)
					errorWarning("That was Not an Option");
				else
					correct = true;
			}

		if (id.empty() || name.empty() || username.empty() || password.empty())
			choice = 0;

		if (choice == 1)
		{
			char *cId = new char[id.length() + 1];
			strcpy(cId, id.c_str());

			if ((searchUserDatabase("id", cId, false)))//the bool means that we do not want to remove a user
			{
				errorWarning("User Already in the Database");
			}
			else
			{
				adm.createUser(newUser, id, name, username, password);
				adm.storeToDatabase("UserDatabase.xml", newUser);
				exit = true;
			}
			delete[] cId;
		}
		else
		{
			errorWarning("Admin Typed In User Wrong. Try Again.");
			correct = false;
		}
	}

	delete newUser;
	newUser = 0;

	/* there is not that much error checking going on here,
	maybe because we trust the admin to know what he is doing */
}
void readUsers()
{
	Admin adm(" ", " ", " ", " ");
	deque<User*> dqUserList;
	string id, name, username, password;
	int count = 0;
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("UserDatabase.xml");
	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr)
	{
		errorWarning("Database Failed To Open"); // Need to have a preinitialized database for this to work (use the xml file I included on github)
		getchar();
		exit(1);
	}
	XMLElement* userElement = xmlDoc.FirstChildElement()->FirstChildElement("User");
	for (tinyxml2::XMLElement* child = userElement; child != NULL; child = child->NextSiblingElement())
	{
		id = child->Attribute("id");
		name = child->Attribute("name");
		username = child->Attribute("username");
		password = child->Attribute("password");

		User* newUser = new User;
		adm.createUser(newUser, id, name, username, password);
		dqUserList.push_back(newUser); // make sure to deallocate all of these when you are done
	}
	for (deque<User*>::iterator i = dqUserList.begin(); i != dqUserList.end(); ++i)
	{
		adm.displayUserData(dqUserList.at(count));
		cout << '\n';
		++count;
	}
	count = 0;
	for (deque<User*>::iterator i = dqUserList.begin(); i != dqUserList.end(); ++i)
	{
		delete dqUserList.at(count);
		dqUserList.at(count) = 0;
		++count;
	}
	dqUserList.clear();

	cout << "\n\n\tTotal Users In Database: " << count;
	std::cin.clear();
	std::cin.ignore();
}
void searchUsers(bool remove)
{
	int choice = 0;
	string searchKey = "";
	char * searchAttribute = "";
	User* desiredUser = NULL;
	
	while (!(choice = chooseUserSearchAttribute()) || (choice > 5 || choice < 1))
	{
		errorWarning("That Was Not One of the Options");
	}
	if (choice == 1)
		searchAttribute = "id";
	if (choice == 2)
		searchAttribute = "name";
	if (choice == 3)
		searchAttribute = "username";
	if (choice == 4)
		searchAttribute = "password";

	searchKey = chooseUserSearchKey(searchAttribute);

	if (!searchKey.empty())
	{
		desiredUser = searchUserDatabase(searchAttribute, searchKey, remove);
		Admin adm("", "", "", "");
		if (desiredUser->getID() == "fail")
			cout << "\n\n\t\tUser Deleted";
		else if (desiredUser != NULL && desiredUser->getID() != "fail")
			adm.displayUserData(desiredUser);
		else if (desiredUser->getID() != "fail")
			errorWarning("User Not Found");
	}
}
int chooseUserSearchAttribute()
{
	int x = 0;
	cout << "\n\n\tSelect the Key to Search For:"
		<< "\n\t1. Id"
		<< "\n\t2. Name"
		<< "\n\t3. Username"
		<< "\n\t4. Password"
		<< "\n\t5. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;

}
string chooseUserSearchKey(string searchAttribute)
{
	string searchKey = "";
	bool exit = false;
	int choice = 0;
	while (!exit)
	{
		searchKey = "";
		choice = 0;
		cout << "\n\tEnter a " << searchAttribute << ": ";
		getline(std::cin, searchKey);

		cout << "\n\n\tYou Entered: "
			<< "\n\t\t" << searchAttribute << ": " << searchKey
			<< "\n\n\tIs This Correct(1=T,0=F, 2=EXIT)?";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore();
		if (choice == 2)
		{
			searchKey = "";
			exit = true;
		}
		else if (choice == 1)
			exit = true;
		else
			errorWarning("You changed Your Mind. Try Again.");
	}
	return searchKey;
}
User* searchUserDatabase(char * attribute, string searchItem, bool remove) // remove should be set to TRUE if you want to delete a user from the database
{
	Admin adm(" ", " ", " ", " ");
	string id, name, username, password;
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("UserDatabase.xml");
	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr)
	{
		errorWarning("Database Failed To Open"); // Need to have a preinitialized database for this to work (use the xml file I included on github)
		getchar();
		exit(1);
	}
	XMLElement* userElement = xmlDoc.FirstChildElement()->FirstChildElement("User");

	if (!((attribute == "id") || (attribute == "name") || (attribute == "username") || (attribute == "password")))
	{
		errorWarning("That Is Not a Searchable Item");
		return NULL;
	}
	
	for (tinyxml2::XMLElement* child = userElement; child != NULL; child = child->NextSiblingElement())
	{
		if (!remove)
		{
			if (searchItem == child->Attribute(attribute))
			{
				// User was found in the database, so: make the user from the database and return him!
				Admin adm("", "", "", "");
				User * foundUser = new User;
				adm.createUser(foundUser, child->Attribute("id"), child->Attribute("name"), child->Attribute("username"), child->Attribute("password"));
				return foundUser;
			}
		}
		else if (remove)
		{
			if (searchItem == child->Attribute(attribute))
			{
				// User was found in the database, so: delete him
				Admin adm("", "", "", "");
				User * foundUser = new User;
				adm.createUser(foundUser, child->Attribute("id"), child->Attribute("name"), child->Attribute("username"), child->Attribute("password"));
				
				cout << "\n\n\tUser Being Deleted:";
				adm.displayUserData(foundUser);
				xmlDoc.FirstChildElement()->DeleteChild(child);
				adm.createUser(foundUser, "fail", "fail", "fail", "fail");
				xmlDoc.SaveFile("UserDatabase.xml");
				return foundUser;
			}
		}
	}

	std::cin.clear();
	std::cin.ignore();
	return NULL;
}
User* verifyLogin(string username, string password)
{
	Admin adm(" ", " ", " ", " ");
	User * newUser = new User; // make sure to deallocate!!!!!
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("UserDatabase.xml");
	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr)
	{
		errorWarning("Database Failed To Open"); // Need to have a preinitialized database for this to work (use the xml file I included on github)
		getchar();
		exit(1);
	}
	XMLElement* userElement = xmlDoc.FirstChildElement()->FirstChildElement("User");

	for (tinyxml2::XMLElement* child = userElement; child != NULL; child = child->NextSiblingElement())
	{
		if (username == child->Attribute("username"))
		{
			if (password == child->Attribute("password"))
			{
				adm.createUser(newUser, child->Attribute("id"), child->Attribute("name"), username, password);
				return newUser;
			}
		}
	}
	return NULL;
	std::cin.clear();
	std::cin.ignore();
}
#endif
