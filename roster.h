#include <iostream>
#include <vector>
#include "student.h"


using namespace std;

class Roster {
public:

	// Index for classRosterArray
	int LastIndex = -1;

	// Created fixed integer size for classRosterArray
	const static int numStudents = 5;
	
	// Array of Pointers 
	Student* classRosterArray[numStudents];
	
	 // Constructor
	Roster();
	
	// Parsing strings in data
	void parseStudents(string row);

	// Sets instance variables from part D1 and updates the roster
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	// Prints a complete tab-seperated list of student data 
	void printAll();

	// Prints out student information for a degree program specified by enumerated type
	void printByDegreeProgram(DegreeProgram degreeType);

	// Verifies student email addresses and displays all invalid email address to the user
	void printInvalidEmails();

	// Prints a student's average number of days in the three courses 
	void printAverageDaysInCourse(string studentID);

	// E3.B - Removes students from the roster by Student ID 
	void removeID(string studentID);

	// Destructor
	~Roster();

};