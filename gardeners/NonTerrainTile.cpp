#include "NonTerrainTile.hpp"

void LakeTile::newTilePlacedNext(Tile *t)
{
    if (!t->isOpen())
        placedNext++;
}

int LakeTile::worthPoints() const
{
    if (placedNext >= 4)
        return 1;

    return 0;
}

LakeTile::LakeTile()
{
    openSurface = SDL_LoadBMP("files/sprites/fence.bmp");
    surroundedSurface = SDL_LoadBMP("files/sprites/bean.bmp");
}

void LakeTile::draw(Renderer *r, int x, int y)
{
    if (openTexture == nullptr)
        openTexture = SDL_CreateTextureFromSurface(r->getSDLRenderer(), openSurface);

    if (surroundedTexture == nullptr)
        surroundedTexture = SDL_CreateTextureFromSurface(r->getSDLRenderer(), surroundedSurface);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    rect.w = 64;
    rect.h = 64;

    SDL_Texture* texToUse = openTexture;

    SDL_Color blue = {55, 55, 200, 255};
    SDL_Color lblue = {155, 155, 200, 255};


    r->fillRect(rect, lblue);

    if (placedNext >= 4)
    {
        texToUse = surroundedTexture;
        r->fillRect(rect, blue);
    }



    //r->drawTexture(texToUse, rect);
}

std::string LakeTile::getName() const
{
    return "Lake";
}

LakeTile::~LakeTile()
{
    SDL_DestroyTexture(openTexture);
    SDL_DestroyTexture(surroundedTexture);

    SDL_FreeSurface(openSurface);
    SDL_FreeSurface(surroundedSurface);
}

std::string EmptyTile::getName() const
{
    return "Empty";
}

bool EmptyTile::isOpen() const
{
    return true;
}
