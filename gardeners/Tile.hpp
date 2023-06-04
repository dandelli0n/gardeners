#include <string>

#ifndef GARDENERS_TILE_HPP
#define GARDENERS_TILE_HPP

#include "Renderer.hpp"

class Tile
{
public:
    virtual void newTilePlacedNext(Tile* t);
    virtual int worthPoints() const;

    virtual bool isOpen() const;

    virtual void draw(Renderer* r, int x, int y);

    virtual std::string getName() const = 0;
};


#endif //GARDENERS_TILE_HPP
