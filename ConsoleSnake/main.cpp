// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

Vector2D pos = { 5, 5 };

void move()
{
    pos.x += 1;
}

int main()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    using std::chrono::system_clock;
    steady_clock::time_point lastCheckpoint = steady_clock::now();
    bool keepGoing = true;
    long clock = 0;
    const long updateSeperationMilliseconds = 500;
    while (keepGoing)
    {
        steady_clock::time_point now = steady_clock::now();
        long millisecondsDiffernce = duration_cast<milliseconds>(now - lastCheckpoint).count();
        if (millisecondsDiffernce >= updateSeperationMilliseconds)
        {
            move();
            lastCheckpoint = now;
        }
        drawMap(pos);
        keepGoing = handleControls();
        sleep_for(nanoseconds(1000));
    }
}

