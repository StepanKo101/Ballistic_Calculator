#include <iostream>
#include "struct.h"
using std::cout, std::cin;

int asker();

// Mark your position
void playerPos ()
{
    cout << "Enter your X coordinate (example: 00437):\n";
    positioning::pos.xAxis = asker();
    cout << "\nEnter your Y coordinate (example: 01233):\n";
    positioning::pos.yAxis = asker();
}

// Mark target position
void targetPos ()
{
    cout << "\nEnter target's X coordinate (example: 01710):\n";
    positioning::target.xAxis = asker();
    cout << "\nEnter target's Y coordinate (example: 40180):\n";
    positioning::target.yAxis = asker();
}

// Mark splash position for corrections
void splashPos ()
{
    cout << "\nEnter splash X coordinate (example: 01710):\n";
    positioning::splash.xAxis = asker();
    cout << "\nEnter splash Y coordinate (example: 40180):\n";
    positioning::splash.yAxis = asker();
}
