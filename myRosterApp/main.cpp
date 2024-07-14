#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Drew,Haile,drew.haile@outlook.com,27,11,22,33,SOFTWARE"
};

int main()
{

	// Create instance of Roster class
	Roster classRoster;

	// Add each student to classRoster (Add function is called within the parse function.)
	for (int i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();
	classRoster.printInvalidEmails();

	cout << "Displaying Average Days Per Course: " << endl << endl;
	for (int i = 0; i < 5; ++i) { // Loop through classRosterArray, using an accessor to get current object's student id.
		string studentID = classRoster.classRosterArray[i]->getStudentID();
		classRoster.printAverageDaysInCourse(studentID);
	}

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	// Calling destructor for memory release.
	classRoster.~Roster();

	return 0;
}
