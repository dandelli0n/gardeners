#include <string>

#ifndef GARDENERS_TILE_HPP
#define GARDENERS_TILE_HPP

#include "Renderer.hpp"

class Tile
{
public:
    //checks if a new tile is placed next to the current one
    virtual void newTilePlacedNext(Tile* t);
    //checks if the tile is worth points
    virtual int worthPoints() const;
    //checks if the current tile's type is open (returns false)
    virtual bool isOpen() const;
    //draws the tile at X and Y coordinates
    virtual void draw(Renderer* r, int x, int y);
    //returns the name of the tile
    virtual std::string getName() const = 0;
};


#endif //GARDENERS_TILE_HPP
