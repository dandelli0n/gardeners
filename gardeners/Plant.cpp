//
// Created by Vikiii on 14/05/2023.
//

#include "Plant.hpp"
#include <fstream>
#include <utility>

Plant::Plant() :  tile()
{
    int t_num = rand() % plants.size(); //need to do something about duplications but rn i cant
    name = plants.at(t_num).name;
    tile.set_type((plants.at(t_num).get_tile().get_type()));
    shape = plants.at(t_num).get_shape();
    duration = plants.at(t_num).get_duration();
}


Plant::Plant(std::string n, TerrainTile::Type type, Shape s, int time) : tile(type)
{
    name = std::move(n);
    shape = s;
    tile.set_type(type);
    duration = time;
}

TerrainTile Plant::get_tile()
{
    return tile;
}

Shape Plant::get_shape()
{
    return shape;
}

int Plant::get_duration()
{
    return duration;
}

void Plant::load_plant()
{
    std::ifstream f;
    f.open("plants.txt"); //file does not exist yet
    std::string buf;

    std::string name;
    Shape shape;
    TerrainTile::Type type;
    int duration;
    bool boolbuf[16];

    while(std::getline(f, buf))
    {
        name = buf;
        std::getline(f, buf);
        for (int i = 0; i < 16; ++i)
        {
            boolbuf[i] = (buf[i] == '1');
        }

        f >> buf;
        type = TerrainTile::string_to_type(buf);

        f >> duration;
        shape.align();
        plants.emplace_back(name, type, shape, duration);
    }
    f.close();
}





