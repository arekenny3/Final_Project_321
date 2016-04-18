#include <iostream>
#include <string>

using namespace std;

class Exam
{
  protected:
	int examID;
	int examDay;
	int examWeek;
	int examHour;
	int examClass;
	string examDescription;
  public:
	Exam() {}
	Exam(int, int, int, int, int, string);
	
	ind getExamID {return examID;}
	int getDay {return examDay;}
	int getWeek {return examWeek;}
	int getHour {return examHour;}
	int getClass {return examClass;}  
	int getDescription {return examDescription;}
};

Exam::Exam(int ID, int day, int week, int hour, int class, string description)
{
	examID = ID;
	examDay = day;
	examWeek = week;
	examHour = hour;
	examClass = class;
	examDescription = description;
}

class Course
{
protected:
	int courseID;
	string courseName;
	string courseDescription;
	string instructorID;
public:
	Course() {}
	Course(int, string, string, string);

	int getCourseID() {return courseID;}
	string getName {return courseName;}
	string getInstructor {return instructorID;}
	string getDescription; {return courseDescription;}
};

Course::Course(int ID, string name, string description, string instructor)
{
	courseID = ID:
	courseName = name;
	courseDescription = description;
	instructorID = instructor;
}
