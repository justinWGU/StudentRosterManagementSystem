#ifndef STUDENTH
#define STUDENTH
#include "degree.h"
#include <string>
using namespace std;

class Student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age{};
    int daysToComplete[3]{};
    enum DegreeProgram degreeProgram;

public:

    // constructors
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram);

    // setter functions
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3); // Don't pass in array. Instead pass in index and value you want to set.
    void SetDegreeprogram(DegreeProgram degreeProgram);

    // getter functions
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    int GetDaysToComplete(int course) const; // Pass in index that you want returned
    DegreeProgram GetDegreeProgram() const;
    void Print();

};


#endif

