#include "Controls.h"

bool keyDown(char keyCode)
{
    return GetKeyState(keyCode) & 0x8000;
}


bool handleControls(Vector2D* facing, Vector2D piece2Pos, Vector2D headPos)
{
    if (keyDown('Q'))
    {
        return false;
    }
    Vector2D newFacing = *facing;
    if (keyDown('W'))
    {
        newFacing = {0,-1};
    }
    if (keyDown('S'))
    {
        newFacing = { 0,1 };
    }
    if (keyDown('A'))
    {
        newFacing = {-1,0};
    }
    if (keyDown('D'))
    {
        newFacing = { 1,0 };
    }
    if (*facing == newFacing)
    {
        return true;
    }
    if ((headPos + newFacing) != piece2Pos)
    {
        *facing = newFacing;
    }
    return true;
}