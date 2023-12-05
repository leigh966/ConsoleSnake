#pragma once
#include "Vector2D.h"
#include "Piece.h"

const int maxLength = 100;

class Snake
{
private:
    int numPieces = 0;
    void addHead();
    bool touchingSelf();
    
public:
    bool touchingFood(Vector2D foodPos);
    Snake();
    Piece pieces[maxLength];
    int count();
	bool Move();
    void Grow();
    bool Occupies(Vector2D);
    Piece* Head();
};