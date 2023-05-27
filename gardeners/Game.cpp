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
    Plant::load_plant();

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

