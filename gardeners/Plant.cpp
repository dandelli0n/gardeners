//
// Created by Vikiii on 14/05/2023.
//

#include "Plant.hpp"

Plant::Plant() : name(), tile(), shape()
{ }

Plant::Plant(std::string n, TerrainTile::Type t, Shape s)
{
    name = n;
    shape = s;
    tile.set_type(t);
}

TerrainTile Plant::get_tile()
{
    return tile;
}

Shape Plant::get_shape()
{
    return shape;
}





