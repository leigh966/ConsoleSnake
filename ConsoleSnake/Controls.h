#pragma once
#include "Vector2D.h"
#include <Windows.h>
#include <queue>

bool keyDown(char keyCode);
bool handleControls(Vector2D* facing, Vector2D piece2Pos, Vector2D headPos);
void useInstruction(Vector2D* facing);

