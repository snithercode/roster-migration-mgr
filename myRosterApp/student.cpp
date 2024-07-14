#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// FUNCTION DEFINITIONS
// Default Parameter-less Constructor: Initializes object data members.
Student::Student() {

	cout << "Student();" << endl; // Tracer statement - Shows that function executed.
	this->studentID = "x";
	this->firstName = "x";
	this->lastName = "x";
	this->email = "x";
	this->age = 0;
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = DegreeProgram::UNDECLARED;
}

// Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

// Default Destructor
Student::~Student() {}

// Accessors: For getting each of the data members.
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToComplete() {
	return this->daysToComplete;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

// Mutators: For setting each of the data members. 
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::printStudent() {
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	cout << getEmail() << "\t";
	cout << getAge() << "\t";
	cout << "{";
	int* daysToComplete = this->getDaysToComplete();
	for (int i = 0; i < 3; ++i) {
		cout << daysToComplete[i];
		if (i < 2) {
			cout << ", ";
		}
	}
	cout << "}" << "\t";
	cout << degreeStrings[getDegreeProgram()] << endl;
}