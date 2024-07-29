#ifndef ROSTERH
#define ROSTERH
#include "student.h"
using namespace std;

class Roster
{
public:
    ~Roster();
    void parse(string studentData); // parse calls add function
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram);
    void remove(string studentID); // searches array, removes student w/ matching ID, prints error message if not found
    void printAll(); // can loop through the student print function if they are still in array
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student* classRosterArray[5];
};
#endif     