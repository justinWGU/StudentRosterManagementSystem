// Justin Ortiz 010164085
#include "student.h"
#include "degree.h"
#include "roster.h"
#include <iostream>
#include "RosterCLI.h"

using namespace std;


int main()
{
    cout << "Course title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming language: c++" << endl;
    cout << "Student ID: 010164085" << endl;
    cout << "Name: Justin Ortiz" << endl;
    cout << "\n";

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Justin,Oritz,jort291@wgu.edu,24,20,23,30,SOFTWARE"};
    Roster class_roster;
    for (int i = 0; i < 5; i++) {
        class_roster.parse(studentData[i]);
    }

    class_roster.printAll();
    cout << "\n";

    class_roster.printInvalidEmails();
    cout << "\n";


    for (int i = 0; i < 5; i++)
    {
        class_roster.printAverageDaysInCourse(class_roster.classRosterArray[i]->GetStudentID());
    }

    cout << "\n";

    class_roster.printByDegreeProgram(SOFTWARE);
    cout << "\n";

    class_roster.remove("A3");

    class_roster.printAll();
    cout << "\n";

    class_roster.remove("A3");
    cout << "\n";


    RosterCLI roster_cli = RosterCLI(class_roster);

    return 0;
}