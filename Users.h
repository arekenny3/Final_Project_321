#ifndef USERS
#define USERS
#include <iostream>
#include <string>

using namespace std;

void permissionError()
{
	cout << "\nUser doesn't have permission to do this.\n";
}

/*
Separate these three classes into three separate files. (eventually)
*/

class User
{
protected:
	string itsID;
	string itsName; // could separate to -- itsFirstname and itsLastname
	string itsUsername;
	string itsPassword;
public:
	User() {}
	User(string, string, string, string);
	~User() { }

	string getID() { return itsID; } 
	string getName() { return itsName; }
	string getUsername() { return itsUsername; } 
	string getPassword() { return itsPassword; }

	// Only Admins can do this stuff.
	void setID() { permissionError(); }
	void setName() { permissionError(); }
	void setUsername() { permissionError(); }
	void setPassword() { permissionError(); }

	virtual void displayUserData(User*);

	/*

	This 'User' class gives the basic properties of any  user:
	- an ID number
	- a Person's Real Name
	- the User's Username
	- the User's Password
	This class allows the user to access
	these members through the methods provided

	This class also allows users to modify their
	methods

	*/

};

User::User(string id, string name, string username, string password)
{
	itsID = id;
	itsName = name;
	itsUsername = username;
	itsPassword = password;
}

void User::displayUserData(User* pUser)
{

	if (this->getID() != pUser->getID())
	{
		/* check to make sure that the user is not trying to view someone else */

		cout << '\n' << "Access Denied: User attempting to access other User's data";

	}
	else
	{
		cout << '\n' << "User's Real Name:   " << pUser->getName()  /* students, faculty, plain users can view only their real name and username */
			<< '\n' << "User's Username:    " << pUser->getUsername();
	}
}

class Student : public User
{
public:
	Student() { }
	~Student() { }
};


class Faculty : public User
{
public:
	Faculty() { }
	~Faculty() { }
};

class Admin : public User
{
public:
	Admin() { }
	Admin(string, string, string, string);
	~Admin() { }

	void displayUserData(User*); // only the Admin should be able to see ALL of the users data 

	void createUser(User*, string, string, string, string);

	void changeUserID(User*, string); // change a users ID
	void changeUserName(User*, string); // change a users Name
	void changeUserUsername(User*, string); // change a users Username
	void changeUserPassword(User*, string); // change a users Password
	void setID(string id) {itsID = id;}
	void setName(string name) {itsName = name;}
	void setUsername(string username) {itsUsername = username;}
	void setPassword(string password) {itsPassword = password;}

};

Admin::Admin(string id, string name, string username, string password)
{
	setID(id);
	setName(name);
	setUsername(username);
	setPassword(password);
}

void Admin::displayUserData(User* pUser)
{
	Admin admin_access(pUser->getID(), pUser->getName(), pUser->getUsername(), pUser->getPassword());

	cout << '\n' << "User's ID:          " << admin_access.getID()
		<< '\n' << "User's Real Name:   " << admin_access.getName()
		<< '\n' << "User's Username:    " << admin_access.getUsername()
		<< '\n' << "User's Password:    " << admin_access.getPassword();
}

void Admin::createUser(User* pUser, string id, string name, string username, string password)
{
	User newUser(id, name, username, password);
	*pUser = newUser;
}

void Admin::changeUserID(User* pUser, string id)
{
	User newUser(id, pUser->getName(), pUser->getUsername(), pUser->getPassword());
	*pUser = newUser;
}
void Admin::changeUserName(User* pUser, string name)
{
	User newUser(pUser->getID(), name, pUser->getUsername(), pUser->getPassword());
	*pUser = newUser;
}
void Admin::changeUserUsername(User* pUser, string username)
{
	User newUser(pUser->getID(), pUser->getName(), username, pUser->getPassword());
	*pUser = newUser;
}
void Admin::changeUserPassword(User* pUser, string password)
{
	User newUser(pUser->getID(), pUser->getName(), pUser->getUsername(), password);
	*pUser = newUser;
}
#endif