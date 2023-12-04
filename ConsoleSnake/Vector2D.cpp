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

bool Vector2D::operator!=(const Vector2D& other)
{
    return !(*this == other);
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
    return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator*(const int& factor)
{
    return Vector2D(this->x * factor, this->y * factor);
}


Vector2D::Vector2D(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D()
{

}