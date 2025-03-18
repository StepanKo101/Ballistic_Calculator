#pragma once
#include <iostream>
#include <cmath>

using std::cout, std::cin;


//cin repairs
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// User input (I know it looks like ass, but it works, okay?
int asker()
{
    int x;
    while (true)
    {
        cin >> x;
        if (std::cin.fail())    // If the previous extraction failed
        {
            cout << "\nBad input. Try again. Example: 00325\n";
            std::cin.clear();       // Fix cin
            ignoreLine();           // Remove the bad input
        }
        else
        {
            return x;
        }
    }
}
