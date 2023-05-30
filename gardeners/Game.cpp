//
// Created by Vikiii on 14/05/2023.
//

#include "Game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    points = 0;
    coins = 0;
    load();
}

void Game::set_points(int p)
{
    points = p;
}


void Game::load()
{

}

Board& Game::get_board()
{
    return board;
}

void Game::set_coins(int c)
{
    coins = c;
}

void Game::add_coins(int coin)
{
    coins += coin;
}

int Game::get_coins()
{
    return coins;
}

void Game::place_plant(Plant& p)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(p.get_shape().at(j, i))
            {
                //SDL drawing here
                switch(p.get_tile().get_type())
                {
                    case TerrainTile::Type::TOMATO: //draw red square
                        break;
                    case TerrainTile::Type::SUNFLOWER: //draw yellow square
                        break;
                    case TerrainTile::Type::LETTUCE: //draw green sq
                        break;
                    case TerrainTile::Type::BEAN: //draw brown sq
                        break;
                    default: //draw grey sq
                        break;
                }

            }
        }
    }
}

void Game::run()
{
    Plant::load_plant();
}

void Game::gameLoop()
{

}

