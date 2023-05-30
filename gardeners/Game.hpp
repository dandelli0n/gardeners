

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
    std::vector<Plant> plants;
    int points;
    int coins;


public:
    Game(); //starts up game
    void set_points(int p);
    void add_coins(int);
    void set_coins(int c);
    int get_coins();
    void load(); //ebbe kene betolteni mentett jatekallast, ami ebbe van azt at kene tenni a run()-ba
    Board& get_board();
    void place_plant(Plant& p);
    void run(); // szo szerint ugyanaz ami most load()-ban van
    void gameLoop(); //while(running) frame kirajzolas, input olvasas etc (mint kartografusokba)
    //void save(); //kilepeskor save-el egyet file-ba idk
    //~Game(); //nem kell a smart pointerek miatt

};


#endif //GARDENERS_GAME_HPP
