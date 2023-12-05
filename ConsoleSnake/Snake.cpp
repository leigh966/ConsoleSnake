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
    return headPos == foodPos;
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

const float frameTimeFactor = 0.95f;
void speedUp(long* frameTime)
{
    *frameTime = (int)((float)(*frameTime)*frameTimeFactor);
}

bool Snake::Move(Vector2D* foodPos, long* frameTime)
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
    if (touchingFood(*foodPos))
    {
        Grow();
        foodPos->x = -1; //mark that there is no longer food on the map
        speedUp(frameTime);
    }
    return touchingSelf();
}

Snake::Snake()
{
    addHead();
}

bool Snake::touchingSelf()
{
    Vector2D headPos = Head()->pos;
    for (int i = 2; i < numPieces; i++)
    {
        Vector2D thisPiecePos = pieces[i].pos;
        if (headPos == thisPiecePos) return true;
    }
    return false;
}

bool Snake::Occupies(Vector2D pos)
{
    for (int i = 0; i < numPieces; i++)
    {
        if (pieces[i].pos == pos) return true;
    }
    return false;
}

Piece* Snake::Head()
{
    return pieces;
}