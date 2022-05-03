#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//default constructor parameters
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArray; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse[],
	DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student(){}

// Getters 
string Student::getStudentID() 
	{return this->studentID;}
string Student::getFirstName()
	{return this->firstName;}
string Student::getLastName() 
	{return this->lastName;}
string Student::getEmailAddress() 
	{return this->emailAddress;}
int Student::getAge()
	{return this->age;}
int* Student::getDaysInCourse() 
	{return this->daysInCourse;}
DegreeProgram Student::getDegree() 
	{return this->degreeProgram;}

// Setters 
void Student::setStudentID(string studentID)
	{this->studentID;}
void Student::setFirstName(string firstName) 
	{this->firstName;}
void Student::setLastName(string lastName) 
	{this->lastName;}
void Student::setEmailAddress(string emailAddress) 
	{this->emailAddress;}
void Student::setAge(int age) 
	{this->age;}
void Student::setDaysInCourse(int daysInCourse[]) 
	{for (int i = 0; i < daysArray; ++i) this->daysInCourse[i] = daysInCourse[i];}
void Student::setDegreeProgram(DegreeProgram degreeType) 
	{this->degreeProgram = degreeType;}

// Format to output
void Student::print()
{
	{
		cout << this->getStudentID() << '\t' ;
		cout  << this->getFirstName() << '\t';
		cout  << this->getLastName() << '\t';
		cout << this->getAge() << '\t' << '\t';
		cout << "{"
		<< this->getDaysInCourse()[0] << ',';
		cout << this->getDaysInCourse()[1] << ',';
		cout << this->getDaysInCourse()[2] << "}" << '\t';
		cout <<  degreeProgramString[this->getDegree()] << '\n';
	}
}