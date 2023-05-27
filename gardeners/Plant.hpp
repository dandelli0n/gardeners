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
    int duration;
    static std::vector<Plant> plants;

public:
    //Plant();
    Plant(std::string n, TerrainTile::Type t, Shape s, int time);
    TerrainTile get_tile();
    static void load_plant();
    Shape get_shape();
    int get_duration();

    //void align(); these things are better done in shape class I think

};


#endif //GARDENERS_PLANT_HPP
