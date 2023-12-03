#pragma once
#include <iostream>
#include "ImageGrid.h"
#include "Vector2D.h"
#include "Line.h"
using namespace std;

const int MAP_WIDTH = 20, MAP_HEIGHT = 20;

const int LEFT = 0, RIGHT = MAP_WIDTH - 1, TOP = 0, BOTTOM = MAP_HEIGHT - 1;
const int numberOfLines = 4;
Line lines[numberOfLines] = { {LEFT, BOTTOM, RIGHT, BOTTOM},{LEFT, TOP, RIGHT, TOP},
    {LEFT, TOP, LEFT, BOTTOM},{RIGHT, TOP, RIGHT, BOTTOM} };

void drawLinesToMap(char map[])
{
    // draw lines
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int x = lines[i].x1; x <= lines[i].x2; x++)
        {
            for (int y = lines[i].y1; y <= lines[i].y2; y++)
            {
                map[y * MAP_WIDTH + x] = '~';
            }
        }
    }
}

bool posOnMap(int x, int y)
{
    return x > 0 && y > 0 && x < MAP_WIDTH && y < MAP_HEIGHT;
}

int toArrayIndex(int x, int y)
{
    return y * MAP_WIDTH + x;
}

const int mapArraySize = MAP_WIDTH * MAP_HEIGHT;
char* getMap(Vector2D pos)
{
    //initialise map
    char* map = new char[mapArraySize];

    initializeCharArray(map, mapArraySize, ' ');

    drawLinesToMap(map);

    map[toArrayIndex(pos.x, pos.y)] = '.';

    return map;
}

void drawMap(Vector2D pos)
{
    char* map = getMap(pos);
    char buffer[MAP_WIDTH * 2 * MAP_HEIGHT + MAP_HEIGHT];
    int bufferIndex = 0;
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            buffer[bufferIndex++] = map[y * MAP_WIDTH + x];
            buffer[bufferIndex++] = ' ';
        }
        buffer[bufferIndex++] = '\n';
    }
    cout << "\033[2J\033[1;1H" << buffer; // clear screen and draw from buffer
    delete map;
}

