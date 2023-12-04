#include "Vector2D.h"
void Vector2D::rotateVector(Vector2D* vect, float deg)
{
    int newX = round(vect->x * cos(deg) - vect->y * sin(deg));
    vect->y = round(vect->x * sin(deg) + vect->y * cos(deg));
    vect->x = newX;
}


void Vector2D::transform(int x, int y)
{
    this->x += x;
    this->y += y;
}

bool Vector2D::operator==(const Vector2D& other)
{
    return this->x == other.x && this->y == other.y;
}
