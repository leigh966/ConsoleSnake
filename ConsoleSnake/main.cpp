// ConsoleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"
const int maxLength = (MAP_WIDTH - 1) * (MAP_HEIGHT - 1);
Piece pieces[maxLength];

Vector2D foodPos = { 7,7 };

int numPieces = 0;
bool touchingFood(Vector2D headPos)
{
    return headPos.x == foodPos.x && headPos.y == foodPos.y;
}

void grow()
{
    pieces[numPieces] = Piece();
    pieces[numPieces].pos = pieces[numPieces - 1].pos;
    pieces[numPieces].facing = { 0,0 }; //dont move yet
    numPieces++;

}

void move()
{
    for (int i = 0; i < numPieces; i++)
    {
        pieces[i].pos.transform(pieces[i].facing.x, pieces[i].facing.y);
    }
    for (int i = numPieces - 1; i > 0; i--)
    {

            pieces[i].facing = pieces[i - 1].facing;
        
    }

    if(pieces[numPieces-1].facing.x == 0 && pieces[numPieces-1].facing.y == 0) // if we have a new piece that hasn't moved yet
    {
        pieces[numPieces-1].facing = pieces[numPieces - 2].facing; // start moving new piece
    }
    if (touchingFood(pieces[0].pos))
    {
        grow();
    }
}

void addHead()
{
    pieces[0] = Piece();
    pieces[0].pos = { 5, 5 };
    pieces[0].facing = { 1,0 };
    numPieces = 1;
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

    addHead();

    while (keepGoing)
    {
        steady_clock::time_point now = steady_clock::now();
        long millisecondsDiffernce = duration_cast<milliseconds>(now - lastCheckpoint).count();
        if (millisecondsDiffernce >= updateSeperationMilliseconds)
        {
            move();
            lastCheckpoint = now;
        }
        drawMap(pieces, numPieces, foodPos);
        keepGoing = handleControls(&pieces[0].facing);
        sleep_for(nanoseconds(1000));
    }
}

