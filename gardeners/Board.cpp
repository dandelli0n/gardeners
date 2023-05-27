//
// Created by Vikiii on 14/05/2023.
//

#include "Board.hpp"
#include "NonTerrainTile.hpp"
#include <iostream>



Board::Board()
{

    for (int i = 0; i < width * height; ++i)
    {
        if ((i == 1*11+3) || (i == 2*11+8) || (i==5*11+5) || (i==8*11+2) || (i==9*11+7))
        {
            tiles.push_back(std::make_unique<NonTerrainTile>(NonTerrainTile::Type::LAKE));
        }
        else
        {
            tiles.push_back(std::make_unique<NonTerrainTile>(NonTerrainTile::Type::EMPTY));
        }
    }

    //memory leakage here pls fix later
}

/*void Board::setTile(std::unique_ptr<Tile> t, int x, int y)
{
    tiles[x + width * y] = std::move(t);
}*/

void Board::draw()
{
    for (int i = 0; i < Board::width; ++i)
    {
        for (int j = 0; j < Board::height; ++j)
        {
            tiles[j + width*i]->draw();
        }
        std::cout << std::endl;
    }
}

void Board::set_tile(int sor, int oszl, std::unique_ptr<Tile> t)
{
    tiles[(sor*width) + oszl].swap(t);
}

int Board::get_w()
{
    return width;
}

int Board::get_h()
{
    return height;
}


void Board::place_plant(int x, int y, Plant p)
{
    int ofset = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            set_tile(i, j, std::make_unique<TerrainTile>(p.get_tile().get_type()));//p.get_tile().get_type());
            ofset++;
        }
    }
}

Tile* Board::get_tile_at(int x, int y)
{
    return tiles[x + (width * y)].get();
}



