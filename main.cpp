#pragma once
#include <iostream>
#include <cmath>
#include "struct.h"

// Forward declaration of struct(?)
positioning::Coords positioning::pos = {};
positioning::Coords positioning::target = {};
positioning::Coords positioning::splash = {};
positioning::Coords positioning::difference = {};

void ignoreLine();
void playerPos();
void targetPos();
void splashPos();
void correctionCalc();
void getLegs(positioning::Coords, positioning::Coords);

using std::cout, std::cin;

int main ()
{
    cout <<"Input your position & position of your target.\n";
    cout <<"Use MicroDAGR for better precision.\n";
    cout <<"If no tools available, input your position as precise as possible.\n";
    cout <<"If last digit is unknown, enter 0 instead\n";
    cout <<"Example (with MicroDAGR): 02517\n";
    cout <<"Example (low precision): 02510\n\n";

    //Calculations
    playerPos();
    targetPos();
    getLegs(positioning::pos, positioning::target);

    while (true)
    {
        cout <<"\nChoose an action:";
        cout <<"\n1. Calculate corrections.";
        cout <<"\n2. Input new target position.";
        cout <<"\n3. Input your new position.";
        cout <<"\n4. Start over.";
        cout <<"\n5. Exit.\n\n";

        int selection;
        cin >> selection;

        // cin repairs
        if (std::cin.fail())
        {
            std::cin.clear();
            ignoreLine();
        }

        // Further user actions
        switch (selection)
        {
        case 1:
        {
            splashPos();
            correctionCalc();
            getLegs(positioning::pos, positioning::target);
            break;
        }
        case 2:
        {
            targetPos();
            getLegs(positioning::pos, positioning::target);
            break;
        }
        case 3:
        {
            playerPos();
            getLegs(positioning::pos, positioning::target);
            break;
        }
        case 4:
        {
            playerPos();
            targetPos();
            getLegs(positioning::pos, positioning::target);
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            cout << "\nBad input. Try again.";
        }
        }
    }
}
