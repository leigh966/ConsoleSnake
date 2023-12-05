// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

Vector2D foodPos = { 7,7 };
Vector2D MAP_UPPER_BOUND = { MAP_WIDTH - 2, MAP_HEIGHT - 2 };
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> widthDist(1, MAP_UPPER_BOUND.x);
std::uniform_int_distribution<std::mt19937::result_type> heightDist (1, MAP_UPPER_BOUND.y);
// hacky and will cause slowdowns for late game - change this!!!
void generateFood(Snake* player)
{
    do
    {
        // generate food at random position
        foodPos = {(int)widthDist(rng), (int)heightDist(rng)};
    } while (player->Occupies(foodPos)); // there is a snake piece at this position
}


bool outOfBounds(Vector2D* pos)
{
    return pos->x < 1 || pos->x > MAP_UPPER_BOUND.x || pos->y < 1 || pos->y > MAP_UPPER_BOUND.y;
}

long updateSeperationMilliseconds = 500;
const float frameTimeFactor = 0.95f;
void speedUp()
{
    updateSeperationMilliseconds = (int)((float)(updateSeperationMilliseconds) * frameTimeFactor);
}

bool update(Snake* player)
{
    useInstruction(&player->Head()->facing);
    bool gameOver = player->Move() || outOfBounds(&player->Head()->pos);

    if (gameOver)
    {
        cout << "\nGame Over\nScore: " << player->count() - 1;
        return true;
    }
    if (player->touchingFood(foodPos))
    {
        player->Grow();
        generateFood(player);
        speedUp();
    }
    drawMap(player->pieces, player->count(), foodPos);

    return false;
}

int main()
{
    using namespace std::this_thread; 
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    using std::chrono::system_clock;
    steady_clock::time_point lastCheckpoint = steady_clock::now();
    bool keepGoing = true;
    long clock = 0;
    

    Snake player = Snake();

    while (keepGoing)
    {
        steady_clock::time_point now = steady_clock::now();
        long millisecondsDiffernce = duration_cast<milliseconds>(now - lastCheckpoint).count();
        if (millisecondsDiffernce >= updateSeperationMilliseconds)
        {
            if (update(&player)) return 1;
            lastCheckpoint = now;
        }
        
        keepGoing = handleControls(&player.Head()->facing, &player.pieces[1].pos, &player.Head()->pos);
    }
}

