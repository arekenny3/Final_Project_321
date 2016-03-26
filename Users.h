#include <iostream>
#include <string> //           add an IFNDEF section to this file

using namespace std;


/*
	
		Separate these three classes into three separate files. (eventually)


*/



class User
{
private:
	string itsID;
	string itsName;
	string itsUsername;
	string itsPassword;
public:
	User() {}
	User(string, string, string, string);
	~User() { }

	virtual string getID() { return itsID; } // override this for student and faculty
	virtual string getName() { return itsName; }
	virtual string getUsername() { return itsUsername; } // override this for student and faculty
	virtual string getPassword() { return itsPassword; } // override this for student and faculty

	virtual void setID(string id) { itsID = id; } // override this for student and faculty
	virtual void setName(string name) { itsName = name; } // override this for student and faculty
	virtual void setUsername(string username) { itsUsername = username; } // override this for student and faculty
	virtual void setPassword(string password) { itsPassword = password; } // override this for student and faculty

	/*
	This 'User' class gives the basic properties of any  user:

	- an ID number
	- a Person's Real Name
	- the User's Username
	- the User's Password


	This class allows the user to access
	these members through the methods provided

	This class also allows users to modify their
	methods, BUT this WILL be overridden for students
	and faculty in their classes (students and faculty
	should not be allowed to modify on their own)


	*/

};

User::User(string id, string name, string username, string password)
{
	itsID = id;
	itsName = name;
	itsUsername = username;
	itsPassword = password;
}


class Student : public User
{
public:
	Student() { }
	~Student() { }

};

class Faculty : public Student
{
public:
	Faculty() { }
	~Faculty() { }

};

class Admin : public User
{
public:
	Admin(string, string, string, string);
	~Admin() { }

	void displayUserData(User*); // only the Admin should be able to see ALL of the users data
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
	cout << '\n' << "User's ID:          " << pUser->getID()
		<< '\n' << "User's Real Name:   " << pUser->getName()
		<< '\n' << "User's Username:    " << pUser->getUsername()
		<< '\n' << "User's Password:    " << pUser->getPassword();
}
