#include "Tile.hpp"

int Tile::worthPoints() const
{
    return 0;
}

void Tile::newTilePlacedNext(Tile* t)
{
}

bool Tile::isOpen() const
{
    return false;
}

void Tile::draw(Renderer *r, int x, int y)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    rect.w = 64;
    rect.h = 64;

    SDL_Color color = {255, 0, 0, 255};

    r->drawRect(rect, color);
}
