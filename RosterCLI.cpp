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


    bool running = true;
    while (running) {

        cout << "Welcome to my Student Roster App" << endl;
        cout << "Please choose from one of the following options: " << endl;
        cout << "1. View all students" << endl;
        cout << "2. Search for student by ID" << endl;
        cout << "3. Add student to roster" << endl;
        cout << "4. Delete student by ID" << endl;
        cout << "0. EXIT" << endl;

        int userResponse{-1};
        cin >> userResponse;

        switch (userResponse) {
            case 1:
                cout << "Displaying all students: " << endl;
            break;

            default:
                cout << "Invalid input. Please enter one of the following options: " << endl;
            break;

            case 0:
                cout << "Exiting program." << endl;
                running = false;
        }
    }
}

