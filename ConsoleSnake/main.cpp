// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

Vector2D foodPos = { 7,7 };
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> widthDist(1, MAP_WIDTH-1);
std::uniform_int_distribution<std::mt19937::result_type> heightDist (1, MAP_HEIGHT - 1);
// hacky and will cause slowdowns for late game - change this!!!
void generateFood(Snake player)
{
    do
    {
        // generate food at random position
        foodPos = {(int)widthDist(rng), (int)heightDist(rng)};
    } while (player.Occupies(foodPos)); // there is a snake piece at this position
}


bool outOfBounds(Vector2D* pos)
{
    return pos->x < 1 || pos->x > MAP_WIDTH - 1 || pos->y < 1 || pos->y > MAP_HEIGHT - 1;
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

    Snake player = Snake();

    while (keepGoing)
    {
        steady_clock::time_point now = steady_clock::now();
        long millisecondsDiffernce = duration_cast<milliseconds>(now - lastCheckpoint).count();
        if (millisecondsDiffernce >= updateSeperationMilliseconds)
        {
            useInstruction(&player.pieces[0].facing);
            bool gameOver = player.Move(&foodPos) || outOfBounds(&player.pieces[0].pos);
            if (foodPos.x == -1) generateFood(player);
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

