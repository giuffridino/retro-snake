#pragma once
#ifndef __Constants__
#define __Constants__

#include "raylib.h"
#include "raymath.h"
#include <deque>

inline Color green = {173, 204, 96, 255};
inline Color darkGreen = {43, 51, 24, 255};

inline const int rectThickness = 5;

namespace Constants
{
    const int cellSize = 30;
    const int cellCount = 25;
    const int offsetBorder = 75;
    const int frameWidthHeight = cellSize * cellCount;
}

inline bool isElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(element, deque[i]))
        {
            return true;
        }
    }
    return false;
}

#endif // __Constants__