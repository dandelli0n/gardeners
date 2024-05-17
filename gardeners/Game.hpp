

#ifndef GARDENERS_GAME_HPP
#define GARDENERS_GAME_HPP

#include "Task.hpp"
#include "Board.hpp"
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Renderer.hpp"

//most of the game logic is declared here

class Game
{
private:
    enum class Season
    {
        Spring, Summer, Fall, Winter
    } season = Season::Spring;


    int currentTime = 0;

    std::string playername;
    Board board;
    Task tasks[4];

    std::vector<Plant> plants;
    Plant portal;
    std::vector<Task> loadedTasks;

    Plant currentPlant;
    std::unique_ptr<Tile> demoTile;

    int points = 0;
    int coins = 0;


    Renderer* renderer;

    bool shouldRun = true;

    //struct for all potential inputs
    struct Input
    {
        bool clicked;
        int mouseX;
        int mouseY;

        bool enter;
        bool testInput;

        bool rotate;
        bool mirror;

        char textInputBuffer[256] = {};

        bool scrollUp;
        bool scrollDown;

        inline void clearTextInput() { textInputBuffer[0] = '\0'; }
    } input;

    //struct for the resources needed for rendering
    struct GameResources
    {
        TTF_Font * mainFont;
        TTF_Font * bigFont;

        SDL_Color backgroundColor = {240, 199, 196, 255};

        SDL_Color mainDarkColor = {174, 100, 160, 255};
        SDL_Color mainBrightColor = {245, 220, 220, 255};

        SDL_Color mainTextColor = {177,112,123,255};
        SDL_Color accentTextColor = {};

        SDL_Color hoverOkColor =  {123,177,123,255/2};
        SDL_Color hoverBadColor =  {177,123,123,255/2};
    } gameResources;

    //handles the possible events
    void eventHandler();

    //class of the main views in the game
    enum class View
    {
        MainMenu, MainGame, NewGame, QuestsView, EndGame
    } view = View::MainMenu;

    //advances the game to the next season
    void nextSeason();
    //gets the max time to the current season
    int getSeasonTime() const;
    //converts current season name to string
    std::string getSeasonString() const;
    //returns the active quests' IDs
    std::pair<int, int> getCurrentQuestIds();

    //renders "main menu" view
    void mainMenuView();
    //renders "main game" view
    void mainGameView();
    //renders "new game" view
    void newGameView();
    //renders "quests" view
    void questsView();
    //renders "game end" view
    void endGameView();

    //switches current view to the specified one
    void switchView(View newView);
    //sets up game
    void setupGame();

public:
    Game(Renderer* renderer); //starts up game
    //returns number of coins
    int getCoins() const;
    //runs the game
    void run();
    //main game loop
    void gameLoop();

};


#endif //GARDENERS_GAME_HPP
