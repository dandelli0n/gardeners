#ifndef GARDENERS_GEOMETRY_HPP
#define GARDENERS_GEOMETRY_HPP

#include <SDL.h>

bool checkCoordsInRect(int x, int y, SDL_Rect rect);
SDL_Rect bigger(SDL_Rect& rect, int size);

#endif //GARDENERS_GEOMETRY_HPP
