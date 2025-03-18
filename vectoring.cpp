#pragma once
#include <iostream>
#include <cmath>

void trueVectorCalc(double x);
void gameVectorCalc (double x);
void gameMilradsCalc (double x);
void adjustGameMilradsCalc (double x);

using std::cout, std::cin;

//getting raw vector data
void rawVector (double x, double y)
{
    double vectorRaw = atan2(x, y);
    cout << "\nTEST\n" <<vectorRaw << "\nTEST\n";
    trueVectorCalc(vectorRaw);
    gameMilradsCalc(vectorRaw);
}

// Convert raw data to regular degrees
void trueVectorCalc(double x)
{
    x = x * (180 / M_PI);
    if (x < 0)
    {
        x += 360;
    }
    gameVectorCalc(x);
}

// Adjust for game's coordinate system (0° as north, clockwise rotation)
void gameVectorCalc (double x)
{
    x = 90 - x; // Rotate 90° counterclockwise
    if (x < 0)
    {
        x += 360;
    }
    cout << "Vector: ";
    cout << static_cast<int>(x);
    cout << " (degrees)\n";
}

// Convert raw data to NATO mils
void gameMilradsCalc (double x)
{
    x = x * (6400 / (2 * M_PI));
    if (x < 0)
    {
        x += 6400;
    }
    adjustGameMilradsCalc(x);
}

//Adjust NATO mils for game's coordinate system
void adjustGameMilradsCalc (double x)
{
    x = 1600 - x; // Rotate 1600 mils counterclockwise
    if (x < 0)
    {
        x += 6400;
    }
    cout << "Vector: ";
    cout << static_cast<int>(x);
    cout << " (NATO mils)\n";
}

