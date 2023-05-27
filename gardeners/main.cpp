#include <iostream>
#include "Task.hpp"
#include "Game.hpp"
#include "NonTerrainTile.hpp"
//#include "Plant.hpp"
#include "Task.hpp"
#include "TerrainTile.hpp"
#include "Tile.hpp"
#include "Board.hpp"

int main() {
    Game game;
    Board& b = game.get_board();
    //b.draw();
    std::string a;
    std::string str = "b";
    a = str;
    b.set_tile(1, 2, std::make_unique<TerrainTile>(TerrainTile::Type::TOMATO));
    //b.draw();
    //int point = b.tomato_quest();
    //std::cout << a << ", " << str << ", tomatoes: " << point;
    return 0;
}
