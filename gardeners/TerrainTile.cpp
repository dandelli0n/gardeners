//
// Created by Vikiii on 14/05/2023.
//

#include "TerrainTile.hpp"
#include <iostream>
TerrainTile::TerrainTile()
{
    type = Type::TOMATO;
}

TerrainTile::TerrainTile(Type t)
{
    type = t;
}

void TerrainTile::set_type(TerrainTile::Type t)
{
    type = t;
}

/*TerrainTile::TerrainTile()
{
    type = Type::VOID;
}*/

void TerrainTile::draw()
{
    switch (type)
    {
        case Type::TOMATO:
            std::cout << "[T]";
            break;
        case Type::LETTUCE:
            std::cout << "[L]";
            break;
        case Type::BEAN:
            std::cout << "[B]";
            break;
        case Type::SUNFLOWER:
            std::cout << "[S]";
            break;

    }



}

std::string TerrainTile::getName()
{
    switch (type)
    {
        case Type::TOMATO:
            return "tomato";
        case Type::LETTUCE:
            return "lettuce";
        case Type::BEAN:
            return "bean";
        case Type::SUNFLOWER:
            return "sunflower";
    }
}

TerrainTile::Type TerrainTile::get_type()
{
    return type;
}

TerrainTile::Type TerrainTile::string_to_type(const std::string &s) {

    if(s == "tomato")
        return Type::TOMATO;
    else if (s == "lettuce")
        return Type::LETTUCE;
    else if(s == "bean")
        return Type::BEAN;
    else if (s== "sunflower")
        return Type::SUNFLOWER;
    else
        throw "Invalid type string!";
}



