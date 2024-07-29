#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

Roster::~Roster()
{
    cout << "Destructor is now running" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)

{
    static int count = 0;
    Student* ptr = nullptr;
    ptr = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, degreeProgram);
    classRosterArray[count] = ptr;
    count++;
}

void Roster::parse(string studentData)
{
    // "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"
    int lhs = 0;
    int rhs = studentData.find(',', lhs);
    string studentID = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string age = studentData.substr(lhs, rhs - lhs);
    int intAge = stoi(age);


    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string days1 = studentData.substr(lhs, rhs - lhs);
    int intDays1 = stoi(days1);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string days2 = studentData.substr(lhs, rhs - lhs);
    int intDays2 = stoi(days2);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string days3 = studentData.substr(lhs, rhs - lhs);
    int intDays3 = stoi(days3);

    lhs = rhs + 1;
    string program = studentData.substr(lhs);
    DegreeProgram prg;

    if (program == "SOFTWARE")
        prg = SOFTWARE;

    else if (program == "SECURITY")
        prg = SECURITY;

    else if (program == "NETWORK")
        prg = NETWORK;

    add(studentID, firstName, lastName, emailAddress, intAge, intDays1, intDays2, intDays3, prg);

}

void Roster::remove(string studentID)
{
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            if (classRosterArray[i]->GetStudentID() == studentID)
            {
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
            }
        }
        else
            cout << "Student with student ID: " << studentID << " not found" << endl;

    }
}

void Roster::printAll()
{

    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->Print();
        }
    }

}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
            int num1 = classRosterArray[i]->GetDaysToComplete(1);
            int num2 = classRosterArray[i]->GetDaysToComplete(2);
            int num3 = classRosterArray[i]->GetDaysToComplete(3);
            int sum = (num1 + num2 + num3) / 3;

            cout << "Student ID: " << studentID << " Average days in course: " << sum << endl;
        }

        else if (classRosterArray[i] == nullptr)
        {
            cout << "Student ID: " << studentID << " not found" << endl;
        }
    }

}

void Roster::printInvalidEmails()
{
    string email;
    cout << "Invalid emails: " << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            email = classRosterArray[i]->GetEmailAddress();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
            {
                cout << email << endl;
            }
        }
    }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    string degPrgm;
    if (degreeProgram == 0)
        degPrgm = "NETWORK";
    else if (degreeProgram == 1)
        degPrgm = "SECURITY";
    else if (degreeProgram == 2)
        degPrgm = "SOFTWARE";

    cout << "All students in " << degPrgm << " degree program: " << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->Print();
        }
    }

}


