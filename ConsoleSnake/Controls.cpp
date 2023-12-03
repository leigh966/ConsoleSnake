#include "Controls.h"

bool keyDown(char keyCode)
{
    return GetKeyState(keyCode) & 0x8000;
}


bool handleControls()
{
    const float speed = 0.1f;
    if (keyDown('Q'))
    {
        return false;
    }
    if (keyDown('W'))
    {
    }
    if (keyDown('S'))
    {
    }
    if (keyDown('A'))
    {
    }
    if (keyDown('D'))
    {
    }

    return true;
}