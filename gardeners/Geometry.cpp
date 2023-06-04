#include "Geometry.hpp"

bool checkCoordsInRect(int x, int y, SDL_Rect rect)
{
    if (x > rect.x && x < rect.x + rect.w)
    {
        if (y > rect.y && y < rect.y + rect.h)
        {
            return true;
        }
    }

    return false;
}

SDL_Rect bigger(SDL_Rect &rect, int size)
{
    SDL_Rect newRect = rect;

    newRect.w += size * 2;
    newRect.h += size * 2;

    newRect.x -= size;
    newRect.y -= size;


    return newRect;
}
