#include "student.h"
#include <iostream>
using namespace std;

// ------------------- Constructors ----------------------

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    daysToComplete[0] = daysToComplete1;
    daysToComplete[1] = daysToComplete2;
    daysToComplete[2] = daysToComplete3;
    this->degreeProgram = degreeProgram;
}

// ------------------------- Setter Functions -------------------------------

void Student::SetStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::SetFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::SetLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::SetAge(int age)
{
    this->age = age;
}

void Student::SetDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3)
{
    daysToComplete[0] = daysToComplete1;
    daysToComplete[1] = daysToComplete2;
    daysToComplete[2] = daysToComplete3;
}

void Student::SetDegreeprogram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}

// -----------------  Getter functions ----------------
string Student::GetStudentID() const
{
    return studentID;
}

string Student::GetFirstName() const
{
    return firstName;
}

string Student::GetLastName() const
{
    return lastName;
}

string Student::GetEmailAddress() const
{
    return emailAddress;
}

int Student::GetAge() const
{
    return age;
}

int Student::GetDaysToComplete(int course) const
{

    if (course == 1)
        return daysToComplete[0];

    else if (course == 2)
        return daysToComplete[1];

    else if (course == 3)
        return daysToComplete[2];

    else
        return -1;
}

DegreeProgram Student::GetDegreeProgram() const
{
    return degreeProgram;
}

void Student::Print()
{
    string degPrgm;
    if (GetDegreeProgram() == 0)
        degPrgm = "NETWORK";
    else if (GetDegreeProgram() == 1)
        degPrgm = "SECURITY";
    else if (GetDegreeProgram() == 2)
        degPrgm = "SOFTWARE";

    cout << studentID << "    " << "First name: " << firstName << "    " << "Last name: " << lastName << "    " << "Age: " << age << "    " << "days in course: " << "[" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "] " << "Degree program: " << degPrgm << endl;
}
