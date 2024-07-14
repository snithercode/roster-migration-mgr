#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {

	// D.1 Variable Declarations
public:

private:

	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;



	// D.2 Function Declarations
public:

	// CONSTRUCTOR & DESTRUCTOR: For object initialization and deletion.
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);
	Student();
	~Student();

	// ACCESSORS: Get data members.
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	// MUTATORS: Set data members using passed-in arguments.
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int DaysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// PRINT: Used to print specific student data.
	void printStudent();


};