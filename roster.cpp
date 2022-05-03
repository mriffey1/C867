#pragma once
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

// Constructor
Roster::Roster(){}

// Parsing out students from studentData
void Roster::parseStudents(string studentData)
{
	DegreeProgram degreeType = NETWORK;
	if (studentData.at(studentData.size() - 1) == 'K') 
	{
		degreeType = NETWORK;
	}
	else if (studentData.at(studentData.size() - 1) == 'Y') 
	{
		degreeType = SECURITY;
	}
	else if (studentData.at(studentData.size() - 1) == 'E') 
	{
		degreeType = SOFTWARE;
	}

	size_t rightSide = studentData.find(",");
	string studentID = studentData.substr(0, rightSide);
	size_t leftSide = rightSide + 1;
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string firstName = studentData.substr(leftSide, rightSide - leftSide);
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string lastName = studentData.substr(leftSide, rightSide - leftSide);
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string emailAddress = studentData.substr(leftSide, rightSide - leftSide);
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int age = stoi(studentData.substr(leftSide, rightSide - leftSide));
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysInCourse1 = stoi(studentData.substr(leftSide, rightSide - leftSide));
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysInCourse2 = stoi(studentData.substr(leftSide, rightSide - leftSide));
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysInCourse3 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);

	// Adding student objects
	add(studentID, 
		firstName, 
		lastName, 
		emailAddress, 
		age, 
		daysInCourse1, 
		daysInCourse2, 
		daysInCourse3, 
		degreeType); 
}

// Sets instance variables from part D1 and updates the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray[++LastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

// Prints a complete tab-seperated list of student data
void Roster::printAll()
{
	// Student::printHeader();
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}

// Prints/Calculates a student's average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << " Student ID: ";
			cout << studentID;
			cout << ",";
			cout << " averages days in course is: ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3;
		
		}

	}cout << endl;
}

// Verifies student email addresses and displays all invalid email addresses to the user
void Roster::printInvalidEmails()
{
	bool invalid = false;
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos)
		{
			invalid = true;
			cout << emailAddress << ":" << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
		if (!invalid) cout << "None" << endl;
	}
}

// Prints out student information for a gree program specified by enumerated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegree() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

//Removal of student based on studentID
void Roster::removeID(string studentID)
{
	bool removal = false;
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			removal = true;
			if (i < numStudents - 1)
			{
				Student* tempHolder = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = tempHolder;
			}
			Roster::LastIndex--;
		}
	}
	if (removal)
	{
		cout << "" << endl;
		this->printAll();
	}
	else cout << "The student with the ID: " << studentID << " was not found." << endl;
}

// Destructor
Roster::~Roster()
{
	cout << "Destructor called" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student: " << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}