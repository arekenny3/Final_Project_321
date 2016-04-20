#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> // platform dependent, consider finding a different solution
#include "Users.h" // currently contains the classes for the User, Admin, and Student
#include "tutorial.h" // tutorial of how to use the classes
#include "tinyxml2.h" // need for the xml database
#include  "d2sDatabaseSystem.h" // DATABASE SYSTEM FOR ACCESSING DATABASE: ADMIN ACCESS ONLY
#include "UserLogin.h" // handles the login of the user and checking for correct login with the database (that function is in DB)
#include "Exam.h"
#pragma warning(disable:4996) // get rid of those nasty warnings

using namespace tinyxml2; // makes life easier
using namespace std; // makes life easier
//Protoyped functions
void welcome();

void d2sMainMenuStudent();
int d2sMainMenuStudentOptions();
void d2sMainMenuFaculty();
int d2sMainMenuFacultyOptions();
void d2sMainMenuAdmin();
int d2sMainMenuAdminOptions();


int main()
{
	//admin_tutorial(); // uncomment if you would like to see how the admin class works. Look at the code as well

	welcome();

	User* newUser = new User; // Memory Leak? I made "new User" all the way through. They all point to the same mem address, but,
					// perhaps deleting one will not delete all? consider implementing differently
	newUser = getUser(); // go through the login and verification process. SHOULD NOT MOVE PAST THIS POINT IF THEY CAN'T LOGIN
	
	if (userType(newUser) == "student")
		d2sMainMenuStudent();
	if (userType(newUser) == "faculty")
		d2sMainMenuFaculty();
	if (userType(newUser) == "admin")
		d2sMainMenuAdmin();

	//Exam * firstExam = new Exam;

	//firstExam->setCourse("ECE 321");

	//firstExam->setDate();
	//firstExam->setDescription("Chapter 2: Printing to the Screen");
	//firstExam->setExamID("M00001");

	delete newUser;
	newUser = 0;
	
	cin.clear();
	cin.ignore();
	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWelcome to D2S (Desire To Schedule)";
}
/*
	requirements for the d2sMainMenu function:

	-selectively choose what options to give users, based on their types
	(HINT: This snippet below will store the usertype into 'type')

				string type = userType(newUser);
				(could be "student", "faculty, or "admin")
	
	-OptionsForAdmin
	  List Admin Options
	-OptionsForFaculty
	  List Faculty Options
	-OptionsForStudent
	  List Student Options

	BONUS:
		make some default options that would be available for anyone (potential future guests)
	
	*/
void d2sMainMenuStudent()
{
	int choice = 0;

	bool exit = false;

	while (!exit)
	{
		while (!(choice = d2sMainMenuStudentOptions()) || (choice > 5 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: //
			break;
		case 2: //
			break;
		case 3: //
			break;
		case 4: //
			break;
		case 5: exit = true;
			break;
		default: // do something
			break;
		}
	}

}
int d2sMainMenuStudentOptions()
{
	int x = 0;

	cout << "\n\n\tAs a Student, you may access:"
		<< "\n\t1. Attendance"
		<< "\n\t2. Grades"
		<< "\n\t3. Job Vacancies"
		<< "\n\t4. Exam Schedule"
		<< "\n\t5. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}

void d2sMainMenuFaculty()
{
	int choice = 0;

	bool exit = false;

	while (!exit)
	{
		while (!(choice = d2sMainMenuFacultyOptions()) || (choice > 5 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: //
			break;
		case 2: //
			break;
		case 3: //
			break;
		case 4: //
			break;
		case 5: exit = true;
			break;
		default: // do something
			break;
		}
	}

}
int d2sMainMenuFacultyOptions()
{
	int x = 0;

	cout << "\n\n\tAs a Faculty, you may access:"
		<< "\n\t1. Student Attendance"
		<< "\n\t2. Student Grades"
		<< "\n\t3. Job Vacancies"
		<< "\n\t4. Exam Schedule"
		<< "\n\t5. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}

void d2sMainMenuAdmin()
{
	int choice = 0;

	bool exit = false;

	while (!exit)
	{
		while (!(choice = d2sMainMenuAdminOptions()) || (choice > 5 || choice < 1))
		{
			errorWarning("That Was Not One of the Options");
		}
		switch (choice)
		{
		case 1: d2sDatabaseSystem();
			break;
		case 2: //
			break;
		case 3: //
			break;
		case 4: //
			break;
		case 5: exit = true;
			break;
		default: // do something
			break;
		}
	}

}
int d2sMainMenuAdminOptions()
{
	int x = 0;

	cout << "\n\n\tAs an Administrator, you may access:"
		<< "\n\t1. D2S Database System"
		<< "\n\t2. Student Grades"
		<< "\n\t3. Job Vacancies"
		<< "\n\t4. Exam Schedule"
		<< "\n\t5. Exit"
		<< "\n\t: ";

	scanf_s("%d", &x);

	getchar();

	return x;
}