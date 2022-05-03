#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
	// F1. Print out the course title, programming language, WGU student ID and name
	cout << "-----------------------------------------------------------" << endl;
	cout << "Class: C867 Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000550488" << endl;
	cout << "Student Name: Megan Riffey" << endl;

	// Requirement A. Modify studentData to include personal information 
	const int numStudents = 5;
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Megan,Riffey,mriffe4@wgu.edu,34, 10, 7, 2,SOFTWARE"
	};
	
	
	// Pulls and displays student data
	Roster classRoster;
	for (int i = 0; i < numStudents; i++) classRoster.parseStudents(studentData[i]);
	cout << "-----------------------------------------------------------" << endl;
	cout << "Class Roster:\n" << endl;
	classRoster.printAll();
	cout << endl;

	// Pulls and displays invalid emails
	cout << "-----------------------------------------------------------" << endl;
	cout << "Displaying invalid Emails:\n" << endl;
	classRoster.printInvalidEmails();
	cout << "-----------------------------------------------------------" << endl;;

	// Pulls and displays average days in course per student
	cout << "Average days in course for each student:\n" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << "-----------------------------------------------------------" << endl;

	// Displays Students in specific degree program
	cout << "Displaying by degree program: " << degreeProgramString[2] << "\n" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "-----------------------------------------------------------" << endl;

	// Removes student A3
	cout << "Removing A3: " << endl;
	classRoster.removeID("A3");
	cout << "-------------------------------------------------------" << endl;

	// Confirms student A3 has been removed
	cout << "Removing A3 again" << endl;
	classRoster.removeID("A3");
	cout << "-------------------------------------------------------" << endl;
	system("pause");
	return 0;
};
