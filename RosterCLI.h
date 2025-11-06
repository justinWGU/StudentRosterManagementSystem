// Created by ojsti on 9/30/2024.
#ifndef ROSTERCLI_H
#define ROSTERCLI_H

#include "roster.h"


// Create menu options for user
class RosterCLI {

    private:
        Roster roster{};
        void add_student();

    public:
        RosterCLI(Roster& roster);
        void start();
        void print_students();
};



#endif //ROSTERCLI_H
