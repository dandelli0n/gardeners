//
// Created by Vikiii on 14/05/2023.
//

#include "Game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    playername = "";
    points = 0;
    coins = 0;
    for(int i = 0; i < 4; ++i)
    {
        tasks[i] = Task();
    }
    board = Board();
}

void Game::set_points(int p)
{
    points = p;
}


void Game::load()
{
    std::ifstream f;
    f.open("");
}

Board& Game::get_board()
{
    return board;
}
void Game::add_coins()
{
    coins++;
}

void Game::set_coins(int c)
{
    coins = c;
}

int Game::get_coins()
{
    return coins;
}

