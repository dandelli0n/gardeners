#ifndef GARDENERS_PLANT_HPP
#define GARDENERS_PLANT_HPP

#include "Tile.hpp"
#include "TerrainTile.hpp"
#include "Shape.hpp"


class Plant
{
private:
    std::string name;
    TerrainTile tile;
    Shape shape;

public:
    Plant();
    Plant(std::string n, TerrainTile::Type t, Shape s);
    TerrainTile get_tile();
    Shape get_shape();
    void rotate();
    void align();
    void mirror();
    void copy();
};


#endif //GARDENERS_PLANT_HPP
