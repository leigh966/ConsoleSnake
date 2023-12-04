#include "Snake.h"

void Snake::Grow()
{
    pieces[numPieces] = Piece();
    pieces[numPieces].pos = pieces[numPieces - 1].pos;
    pieces[numPieces].facing = { 0,0 }; //dont move yet
    numPieces++;

}

bool Snake::touchingFood(Vector2D foodPos)
{
    Vector2D headPos = pieces[0].pos;
    return headPos.x == foodPos.x && headPos.y == foodPos.y;
}


int Snake::count()
{
    return numPieces;
}

void Snake::addHead()
{
    pieces[0] = Piece();
    pieces[0].pos = { 5, 5 };
    pieces[0].facing = { 1,0 };
    numPieces = 1;
}

void Snake::Move(Vector2D foodPos)
{
    for (int i = 0; i < numPieces; i++)
    {
        pieces[i].pos.transform(pieces[i].facing.x, pieces[i].facing.y);
    }
    for (int i = numPieces - 1; i > 0; i--)
    {

        pieces[i].facing = pieces[i - 1].facing;

    }

    if (pieces[numPieces - 1].facing.x == 0 && pieces[numPieces - 1].facing.y == 0) // if we have a new piece that hasn't moved yet
    {
        pieces[numPieces - 1].facing = pieces[numPieces - 2].facing; // start moving new piece
    }
    if (touchingFood(foodPos))
    {
        Grow();
    }
}

Snake::Snake()
{
    addHead();
}