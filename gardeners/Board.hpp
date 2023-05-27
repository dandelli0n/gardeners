#ifndef GARDENERS_BOARD_HPP
#define GARDENERS_BOARD_HPP

#include "Tile.hpp"
#include <vector>
#include <memory>
#include "Plant.hpp"
#include <functional>

class Game;

class Board
{
private:
    int width = 11;
    int height = 11;
    //int coins;
    std::vector<std::unique_ptr<Tile>> tiles;

public:
    Board();
    int get_w();
    int get_h();
    int get_coins() const;

    //void setTile(std::unique_ptr<Tile> t, int x, int y);
    //~Board();
    //void setup();
    void draw();
    int refresh(); //gets coins from the lakes
    void set_tile(int sor, int oszl, std::unique_ptr<Tile> t);
    void place_plant(int x, int y, Plant p);

    //eval fns
};
namespace quests
{
    typedef std::function<int(Game&, Board&)> type;

    int tomato_quest(Game& g, Board& b);
    int sunflower_quest(Game& g, Board& b);
    int bean_quest(Game& g, Board& b);
    int rich_quest(Game& g, Board& b);
}

#endif //GARDENERS_BOARD_HPP
