#include <iostream>
#include "Task.hpp"
#include "Game.hpp"
#include "NonTerrainTile.hpp"
//#include "Plant.hpp"
#include "Task.hpp"
#include "TerrainTile.hpp"
#include "Tile.hpp"
#include "Board.hpp"
#include <algorithm>

struct p {
    int x; int y;
};

int main() {

    auto quest = QuestNameMapper::find("tomato_aasdfasdfsuest");
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


    std::vector<p> v;
    for (int i = 0; i < 99; i++)
        v.push_back({i, i});

    std::sort(v.begin(), v.end(),
              [](const p& a, const p& b){ return a.x > b.y; }
              );


    return 0;
}
