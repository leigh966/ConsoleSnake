#include "Controls.h"

bool keyDown(char keyCode)
{
    return GetKeyState(keyCode) & 0x8000;
}

std::queue<Vector2D> inputQueue;

void useInstruction(Vector2D* facing)
{
    if (inputQueue.size() == 0) return;
    *facing = inputQueue.front();
    inputQueue.pop();
}


bool allowedAfterLastInstruction(Vector2D instruction)
{
    if (inputQueue.size() == 0) return false;
    return instruction * -1 != inputQueue.back() && instruction!= inputQueue.back();
}

bool handleControls(Vector2D* facing, Vector2D piece2Pos, Vector2D headPos)
{

    if (keyDown('Q'))
    {
        return false;
    }

    if (inputQueue.size() <= 5)
    {
        Vector2D newFacing = *facing;
        if (keyDown('W'))
        {
            newFacing = { 0,-1 };
        }
        if (keyDown('S'))
        {
            newFacing = { 0,1 };
        }
        if (keyDown('A'))
        {
            newFacing = { -1,0 };
        }
        if (keyDown('D'))
        {
            newFacing = { 1,0 };
        }
        if (*facing == newFacing)
        {
            return true;
        }
        bool allowedNow = (headPos + newFacing) != piece2Pos;
        if (inputQueue.size() == 0 && allowedNow || inputQueue.size() > 0 && allowedAfterLastInstruction(newFacing))
        {
            inputQueue.push(newFacing);
        }
    }
    return true;
}