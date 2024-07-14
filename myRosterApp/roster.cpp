#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

// Constructor & Deconstructor
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {}

// For adding each student object to classRosterArray. Called within parse function.
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgram degreeProgram) {

    int daysToComplete[3];
    daysToComplete[0] = daysCourse1;
    daysToComplete[1] = daysCourse2;
    daysToComplete[2] = daysCourse3;

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);
            break;
        }
    }

}

// For parsing through each row of data in the studentData string array. 
void Roster::parse(string row) {

    string studentID, firstName, lastName, email;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

    unsigned int i;
    int n = 0;
    int position1 = 0;
    int position2 = 0;
    string dataSubstr;
    string tempArray[9];

    for (i = 0; i < row.length(); ++i) {
        if (row.at(i) == ',') {
            position2 = i;
            dataSubstr = row.substr(position1, (position2 - position1));
            position1 = i + 1;
            tempArray[n] = dataSubstr;
            ++n;
        }
    }
    dataSubstr = row.substr(position1, (row.length() - position1));
    tempArray[n] = dataSubstr;

    if (tempArray[8] == "UNDECLARED") {
        degreeProgram = DegreeProgram::UNDECLARED;
    }
    else if (tempArray[8] == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (tempArray[8] == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

    studentID = tempArray[0];
    firstName = tempArray[1];
    lastName = tempArray[2];
    email = tempArray[3];
    age = stoi(tempArray[4]);
    daysToComplete[0] = stoi(tempArray[5]);
    daysToComplete[1] = stoi(tempArray[6]);
    daysToComplete[2] = stoi(tempArray[7]);


    add(studentID, firstName, lastName, email, age, daysToComplete[0], daysToComplete[1], daysToComplete[2], degreeProgram);
}

// For removing students from the roster by student ID. Will print an error message if student ID does not exist.
void Roster::remove(string studentID) {

    int nStudents = 5;
    bool studentFound = false;
    cout << "Removing student " << studentID << " from roster: ";

    for (int i = 0; i < nStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getStudentID() == studentID) {
                studentFound = true;
                delete classRosterArray[i];
                cout << "Completed" << endl << endl;
                for (i; i < (nStudents - 1); ++i) {
                    classRosterArray[i] = classRosterArray[i + 1];
                }
                classRosterArray[nStudents - 1] = nullptr;
            }
        }
    }

    if (studentFound == false) {
        cout << "Failed " << endl;
        cout << "Student " << studentID << " does not exist in roster." << endl << endl;
    }
}

// For printing a complete tab-separated list of student data.
void Roster::printAll() {

    cout << "Displaying Student Roster: " << endl << endl;

    printColumnLabels();

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->printStudent();
        }
    }

    cout << endl << endl;
}

// For printing a student's average number of days in the three courses. Student is identified by studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {


    int averageDays = 0;
    int* daysToComplete;
    int totalDays = 0;


    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << "Student " << classRosterArray[i]->getStudentID() << ": ";
            daysToComplete = classRosterArray[i]->getDaysToComplete();

            for (int j = 0; j < 3; ++j) {
                totalDays += daysToComplete[j];
            }

            averageDays = totalDays / 3;
            cout << averageDays << " days" << endl;
        }
    }
}

// For verifying student email addresses and then displaying the invalid ones.
void Roster::printInvalidEmails() {

    cout << "Displaying Invalid Emails: " << endl << endl;

    string selectedEmail;

    for (int i = 0; i < 5; ++i) {

        selectedEmail = classRosterArray[i]->getEmail();

        int emailLength = selectedEmail.length();
        int maxIndex = (selectedEmail.length() - 1);
        int atIndex = (selectedEmail.find("@"));
        string emailDomain = selectedEmail.substr((atIndex + 1), (maxIndex + 1) - (atIndex));
        bool validEmail = true;

        if (selectedEmail.find(" ") != string::npos)
        {
            validEmail = false;
        }

        if (emailDomain.find(".") == string::npos)
        {
            validEmail = false;
        }

        if (selectedEmail.find("@") == string::npos)
        {
            validEmail = false;
        }

        if (validEmail == false) {
            cout << selectedEmail << endl;
        }

    }

    cout << endl;
}

// For printing out student information for a degree program specified by an enum type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << endl << "Displaying Students With Selected Degree Program: SOFTWARE" << endl << endl;
    for (int i = 0; i < 5; ++i) {
        DegreeProgram degreeProgram = classRosterArray[i]->getDegreeProgram();
        if (degreeProgram == 3) {
            classRosterArray[i]->printStudent();
        }
    }
    cout << endl;
}

// For printing out column labels.
void Roster::printColumnLabels() {
    cout << "Student ID | First Name | Last Name | Email | Age | Days In Course | Degree Program" << endl << endl;
}