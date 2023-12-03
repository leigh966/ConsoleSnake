// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

int main()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    bool keepGoing = true;
    while (keepGoing)
    {
        drawMap();
        keepGoing = handleControls();
        sleep_for(nanoseconds(1000));
    }
}

