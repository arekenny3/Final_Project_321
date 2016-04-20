#ifndef EXAM
#define EXAM
#include <iostream>
#include <string>
#include "Users.h"
using namespace std;

class Exam
{
protected:
	string itsID;
	string itsDay;
	int itsWeek;
	int itsHour;
	string itsCourse;
	string itsDescription;
public:
	Exam() {}
	Exam(string, string, int, int, string, string);

	string getExamID()	{ return itsID; }
	string getDay()		{ return itsDay; }
	int getWeek()		{ return itsWeek; }
	int getHour()		{ return itsHour; }
	string getCourse()	{ return itsCourse; }
	string getDescription()	{ return itsDescription; }

	void setExamID(string id)	{ itsID = id; }
	void setDay(string day)		{ itsDay = day; }
	void setWeek(int week)		{ itsWeek = week; }
	void setHour(int hour)		{ itsHour = hour; } // use military time
	void setCourse(string course)	{ itsCourse = course; }
	void setDescription(string description)	{ itsDescription = description; }
};

Exam::Exam(string id, string day, int week, int hour, string course, string description)
{
	itsID = id;
	itsDay = day;
	itsWeek = week;
	itsHour = hour;
	itsCourse = course;
	itsDescription = description;
}

class Course
{
protected:
	string itsID;
	string itsName;
	string itsDescription;
	string itsInstructorID;
public:
	Course() {}
	Course(string, string, string, string);

	string getCourseID()	{ return itsID; }
	string getName()		{ return itsName; }
	string getInstructorID(){ return itsInstructorID; }
	string getDescription()	{ return itsDescription; }

	void setCourseID(string id)	{ itsID = id; }
	void setName(string name)		{ itsName = name; }
	void setInstructorID(string instructor)	{ itsInstructorID = instructor; }
	void setDescription(string description)	{ itsDescription = description; }
};

Course::Course(string ID, string name, string description, string instructor)
{
	itsID = ID;
	itsName = name;
	itsDescription = description;
	itsInstructorID = instructor;
}
#endif