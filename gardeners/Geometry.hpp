#ifndef GARDENERS_GEOMETRY_HPP
#define GARDENERS_GEOMETRY_HPP

#include <SDL.h>

//checks if X and Y coordinates are inside the SDL rectangle
bool checkCoordsInRect(int x, int y, SDL_Rect rect);
//makes an SDL rectangle bigger by the given size but keeps it relatively to the center of the previous size
SDL_Rect bigger(SDL_Rect& rect, int size);

#endif //GARDENERS_GEOMETRY_HPP
