#pragma once
#include <cmath>
class Vector2D
{
public:
    int x, y;
    static void rotateVector(Vector2D* vect, float deg);
    void transform(int x, int y);
    bool operator==(const Vector2D& other);
    bool operator!=(const Vector2D& other);
    Vector2D operator+(const Vector2D& other);
    Vector2D(int x, int y);
    Vector2D();
};
