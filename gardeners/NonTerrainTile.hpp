#include "Tile.hpp"

#ifndef GARDENERS_NONTERRAINTILE_HPP
#define GARDENERS_NONTERRAINTILE_HPP

#include "Renderer.hpp"

//special tile, is worth 1 point if all 4 sides are built in
class LakeTile : public Tile
{
public:

    //counts up to 4
    void newTilePlacedNext(Tile* t) override;
    //checks if lake is worth a point
    int worthPoints() const override;
    //draws tile
    void draw(Renderer* r, int x, int y) override;
    //gets name of the tile type
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
    //returns if the tile is open (always returns true)
    bool isOpen() const override;
    //returns tile type's name
    std::string getName() const override;
};


class SoilTile : public Tile
{
    bool open;
    SDL_Texture* soilTexture = nullptr;
    SDL_Surface* soilSurface = nullptr;
public:
    SoilTile();


    //sets the tile type to open
    void openTile();
    //sets the tile type to closed
    void closeTile();
    //returns if the tile is open or not
    bool isOpen() const override;
    //returns tile type's name
    std::string getName() const override;
    //draws tile
    void draw(Renderer* r, int x, int y) override;
    ~SoilTile();
};


#endif //GARDENERS_NONTERRAINTILE_HPP
