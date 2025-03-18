#include <iostream>
#include "struct.h"
using std::cout, std::cin;

void correctionCalc()
{
    positioning::difference.xAxis = positioning::splash.xAxis - positioning::target.xAxis;
    positioning::difference.yAxis = positioning::splash.yAxis - positioning::target.yAxis;
    // Applying corrections to target position
    positioning::target.xAxis = positioning::target.xAxis - positioning::difference.xAxis;
    positioning::target.yAxis = positioning::target.yAxis - positioning::difference.yAxis;
}

