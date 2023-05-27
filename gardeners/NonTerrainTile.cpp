//
// Created by Vikiii on 14/05/2023.
//

#include "NonTerrainTile.hpp"
#include <iostream>

NonTerrainTile::NonTerrainTile(Type a) : type(a)
{}

bool NonTerrainTile::isOpen()
{
    if(type == Type::EMPTY)
        return true;

    return false;
}

void NonTerrainTile::draw()
{
    if(type == Type::EMPTY)
        std::cout << "[ ]";
    else
        std::cout << "[O]";
}

std::string NonTerrainTile::getName()
{
    switch (type)
    {
        case Type::EMPTY:
            return "empty";
        case Type::LAKE:
            return "lake";
    }
}

NonTerrainTile::~NonTerrainTile()
{

}
