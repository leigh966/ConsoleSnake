// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

Vector2D foodPos = { 7,7 };


int main()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    using std::chrono::system_clock;
    steady_clock::time_point lastCheckpoint = steady_clock::now();
    bool keepGoing = true;
    long clock = 0;
    const long updateSeperationMilliseconds = 500;

    Snake player = Snake();

    while (keepGoing)
    {
        steady_clock::time_point now = steady_clock::now();
        long millisecondsDiffernce = duration_cast<milliseconds>(now - lastCheckpoint).count();
        if (millisecondsDiffernce >= updateSeperationMilliseconds)
        {
            bool gameOver = player.Move(foodPos);
            if (gameOver)
            {
                cout << "\nGame Over\nScore: " << player.count() - 1;
                break;
            }
            lastCheckpoint = now;
        }
        drawMap(player.pieces, player.count(), foodPos);
        keepGoing = handleControls(&player.pieces[0].facing, player.pieces[1].pos, player.pieces[0].pos);
        sleep_for(nanoseconds(1000));
    }
}

