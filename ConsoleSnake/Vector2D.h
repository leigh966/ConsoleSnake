#pragma once
#include <cmath>
class Vector2D
{
public:
    int x, y;
    static void rotateVector(Vector2D* vect, float deg);
    void transform(int x, int y);
};
