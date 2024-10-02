// Created by Justin Ortiz on 9/30/2024.

#include <iostream>
#include "RosterCLI.h"
#include "roster.h"
using namespace std;

// ------------------- Constructors ----------------------
RosterCLI::RosterCLI(Roster& roster) {
    this->roster = roster;
}

// ------------------- Methods ----------------------

// display menu
void RosterCLI::start() {

    // intialize data
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Justin,Oritz,jort291@wgu.edu,24,20,23,30,SOFTWARE"};
    for (int i = 0; i < 5; i++) {
        roster.parse(studentData[i]);
    }

    char response = 'y';
    while (response == 'y') {

        cout << "Welcome to my Student Roster App" << endl;
        cout << "Please choose from one of the following options: " << endl;
        cout << "1. View all students" << endl;
        cout << "2. Add student to roster" << endl;
        cout << "3. Search for student by ID" << endl;
        cout << "4. Delete student by ID" << endl;
        cout << "0. EXIT" << endl;

        int userResponse{-1};
        cin >> userResponse;

        switch (userResponse) {
            case 1:
                print_students();
                break;

            case 2:
                add_student();
                break;

            default:
                cout << "Invalid input. Please enter one of the following options: " << endl;
                break;

            case 0:
                cout << "Exiting program." << endl;
                response = 'n';
        }

        // prompt user to repeat menu options
        cout << "\nMake another selection? Press 'y' to continue or press any other button to exit: " << endl;
        cin >> response;
    }
}

void RosterCLI::print_students() {
    cout << "Displaying all students: " << endl;
    roster.printAll();
}

// Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)
void RosterCLI::add_student() {
    cout << "Enter student details." << endl;

    cout << "Student ID: " << endl;
    string student_id;
    cin >> student_id;

    cout << "First name: " << endl;
    string first_name;
    cin >> first_name;

    cout << "Last name: " << endl;
    string last_name;
    cin >> last_name;

    cout << "Email address: " << endl;
    string email;
    cin >> email;

    cout << "Age: " << endl;
    int age;
    cin >> age;

    cout << "Days left to complete first course: " << endl;
    int days1;
    cin >> days1;

    cout << "Days left to complete second course: " << endl;
    int days2;
    cin >> days2;

    cout << "Days left to complete third course: " << endl;
    int days3;
    cin >> days3;

    cout << "Enter # representation of degree program. \n0 for SECURITY\n1 for NETWORK\n2 for SOFTWARE" << endl;
    DegreeProgram deg;
    int user;
    cin >> user;

    switch (user) {

        case 0:
            deg = SECURITY;
        break;

        case 1:
            deg = NETWORK;
        break;

        case 2:
            deg = SOFTWARE;
        break;

        default:
            cout << "Enter a valid number." << endl;
        break;
    }

    roster.add(student_id, first_name, last_name, email, age, days1, days2, days3, deg);
    cout << "Successfully added " << endl;
}

