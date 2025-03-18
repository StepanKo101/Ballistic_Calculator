#pragma once
#include <iostream>
#include <cmath>
#include "struct.h"

void ignoreLine();
void playerPos();
void targetPos();
void distanceCalculator(double x, double y);
void elevationCalculator(double x);
void rawVector (double x, double y);

using std::cout, std::cin;

// Getting legs
void getLegs (positioning::Coords x, positioning::Coords y)
{
    cout <<"\nTARGETING INFORMATION";
    double xLeg {positioning::target.xAxis - positioning::pos.xAxis};
    double yLeg {positioning::target.yAxis - positioning::pos.yAxis};
    distanceCalculator(xLeg, yLeg);
    rawVector (yLeg, xLeg);
}

// Distance calculation using Pythagoras Theorem
void distanceCalculator(double x, double y)
{
    double distance = sqrt(std::pow(x, 2) + std::pow(y, 2));
    cout << "\nDistance: " <<static_cast<int>(distance) <<"m\n";

    // Actions if target out of reach
    if (distance > 3100)
    {
        cout << "\nERROR\nYour target is out of reach! Choose action:";
        while (true)
        {
            cout << "\n1. Change target.";
            cout << "\n2. Change your position.";
            cout << "\n3. Change both.\n";
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
                targetPos();
                getLegs(positioning::pos, positioning::target);
                break;
            }
            case 2:
            {
                playerPos();
                getLegs(positioning::pos, positioning::target);
                break;
            }
            case 3:
            {
                playerPos();
                targetPos();
                getLegs(positioning::pos, positioning::target);
                break;
            }
            default:
            {
                cout << "Bad input. Try again";
            }
            }
            break;
        }
    }
    else
        elevationCalculator(distance);

}

//charge 0 coefficients
const double a1 {-0.00145};
const double b1 {0.637};
const double c1 {1574.05};
//charge 1 coefficients
const double a2 {-0.000134};
const double b2 {-0.1435};
const double c2 {1564.34};
//charge 2 coefficients
const double a3 {-0.00004};
const double b3 {-0.07516};
const double c3 {1562.42501};

//elevation calculation for charges
void elevationCalculator(double distance)
{
    if (distance > 49 && distance < 451)
    {
        int elev = a1 * std::pow(distance, 2) + b1 * distance + c1;
        cout <<"Elevation for charge 0: " << elev <<"\n";
    }
    if (distance > 149 && distance < 1701)
    {

        int elev = a2 * std::pow(distance, 2) + b2 * distance + c2;
        cout <<"Elevation for charge 1: " << elev <<"\n";
    }
    if (distance > 249 && distance < 3101)
    {
        int elev = a3 * std::pow(distance, 2) + b3 * distance + c3;
        cout <<"Elevation for charge 2: " << elev <<"\n";
    }
}
