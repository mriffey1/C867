#include <string>
#include <array>
#include "degree.h"

using namespace std;

class Student {
public:

	const static int daysArray = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysArray];
	DegreeProgram degreeProgram;

public:
	// Constructor
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse[],
		DegreeProgram degreeProgram);

	//Destructor
	~Student();

	// Getters 
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegree();

	// Setters 
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int Age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeType);

	// print() function 
	void print();

};