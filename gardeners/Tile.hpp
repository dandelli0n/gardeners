#include <string>

#ifndef GARDENERS_TILE_HPP
#define GARDENERS_TILE_HPP


class Tile
{
public:
    virtual bool isOpen() = 0;
    virtual void draw() = 0;
    virtual std::string getName() = 0;
};


#endif //GARDENERS_TILE_HPP
