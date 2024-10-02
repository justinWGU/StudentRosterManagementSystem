// Justin Ortiz 010164085
#include "student.h"
#include "degree.h"
#include "roster.h"
#include <iostream>
#include "RosterCLI.h"

using namespace std;


int main()
{

    // start UI
    Roster class_roster = Roster();
    RosterCLI roster_cli = RosterCLI(class_roster);
    roster_cli.start();


    return 0;
}