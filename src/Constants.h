#pragma once
#ifndef __Constants__
#define __Constants__

#include "raylib.h"
#include "raymath.h"
#include <deque>

namespace Constants
{
    const int cellSize = 30;
    const int cellCount = 25;
    const int offsetBorder = 75;
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