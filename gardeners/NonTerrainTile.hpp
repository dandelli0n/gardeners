#include "Tile.hpp"

#ifndef GARDENERS_NONTERRAINTILE_HPP
#define GARDENERS_NONTERRAINTILE_HPP

#include "Renderer.hpp"

class LakeTile : public Tile
{
public:
    void newTilePlacedNext(Tile* t) override;
    int worthPoints() const override;

    void draw(Renderer* r, int x, int y) override;

    std::string getName() const override;

    LakeTile();
    ~LakeTile();

private:
    int placedNext = 0;

    SDL_Texture* openTexture = nullptr;
    SDL_Texture* surroundedTexture = nullptr;

    SDL_Surface* openSurface = nullptr;
    SDL_Surface* surroundedSurface = nullptr;
};

class EmptyTile : public Tile
{
public:
    bool isOpen() const override;
    std::string getName() const override;
};


#endif //GARDENERS_NONTERRAINTILE_HPP
