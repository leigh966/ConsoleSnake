#include "Controls.h"

bool keyDown(char keyCode)
{
    return GetKeyState(keyCode) & 0x8000;
}


bool handleControls(Vector2D* facing)
{
    const float speed = 0.1f;
    if (keyDown('Q'))
    {
        return false;
    }
    if (keyDown('W'))
    {
        *facing = {0,-1};
    }
    if (keyDown('S'))
    {
        *facing = { 0,1 };
    }
    if (keyDown('A'))
    {
        *facing = {-1,0};
    }
    if (keyDown('D'))
    {
        *facing = { 1,0 };
    }

    return true;
}