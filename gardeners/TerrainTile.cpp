//
// Created by Vikiii on 14/05/2023.
//

#include "TerrainTile.hpp"
#include <iostream>

TerrainTile::TerrainTile(Type t)
{
    type = t;
}

void TerrainTile::set_type(TerrainTile::Type t)
{
    type = t;
}

TerrainTile::TerrainTile()
{
    type = Type::VOID;
}

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
        case Type::VOID:
            std::cout << "[?]";
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
        case Type::VOID:
            return "0";
    }
}

TerrainTile::Type TerrainTile::get_type()
{
    return type;
}


