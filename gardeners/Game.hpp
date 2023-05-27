

#ifndef GARDENERS_GAME_HPP
#define GARDENERS_GAME_HPP

#include "Task.hpp"
#include "Board.hpp"
#include <string>


static int season_times[4] = {8, 8, 7, 6};



class Game
{
private:
    std::string playername;
    Board board;
    Task tasks[4];
    //std::vector<Plant> plants;
    int points;
    int coins;


public:
    Game(); //starts up game
    void set_points(int p);
    void add_coins();
    void set_coins(int c);
    int get_coins();
    void load();
    Board& get_board();
    void run();
    void gameLoop();
    void save();
    //~Game();

};


#endif //GARDENERS_GAME_HPP
