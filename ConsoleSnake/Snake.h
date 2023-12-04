#pragma once
#include "Vector2D.h"
#include "Piece.h"

const int maxLength = 100;

class Snake
{
private:
    int numPieces = 0;
    
    void addHead();
    bool touchingFood(Vector2D foodPos);
    bool touchingSelf();
    
public:
    Snake();
    Piece pieces[maxLength];
    int count();
	bool Move(Vector2D* foodPos);
    void Grow();
    bool Occupies(Vector2D);
};