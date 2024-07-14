#pragma once
#include "student.h"

class Roster {

	// Variable Declaration
public:

	// Create an array of pointers, classRosterArray, to hold the data provided in the studentData Table.
	Student* classRosterArray[5];

	// Function Declarations
public:

	// Default Constructor & Deconstructor
	Roster();
	~Roster();

	// For adding each student object to classRosterArray.
	void add(string studentID, string firstName, string lastName, string email, int age, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgram degreeprogram);

	// For parsing through each row of data in the studentData string array.
	void parse(string row);

	// For removing students from the roster by student ID. WIll print an error message if student ID does not exist.
	void remove(string studentID);

	// For printing a complete tab-separated list of student data.
	void printAll();

	// For printing a student's average number of days in the three courses. Student is identified by studentID parameter.
	void printAverageDaysInCourse(string studentID);

	// For verifying student email addresses and then displaying the invalid ones.
	void printInvalidEmails();

	// For printing out student information for a degree program specified by an enum type.
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// For printing out column labels.
	void printColumnLabels();

};