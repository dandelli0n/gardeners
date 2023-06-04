

#ifndef GARDENERS_GAME_HPP
#define GARDENERS_GAME_HPP

#include "Task.hpp"
#include "Board.hpp"
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Renderer.hpp"


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
    std::vector<Task> loadedTasks;

    Plant currentPlant;
    std::unique_ptr<Tile> demoTile;

    int points = 0;
    int coins = 0;


    Renderer* renderer;

    bool shouldRun = true;

    struct Input
    {
        bool clicked;
        int mouseX;
        int mouseY;

        bool enter;

        bool rotate;
        bool mirror;

        char textInputBuffer[256] = {};

        bool scrollUp;
        bool scrollDown;

        inline void clearTextInput() { textInputBuffer[0] = '\0'; }
    } input;

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

    void eventHandler();

    enum class View
    {
        MainMenu, MainGame, NewGame, QuestsView, EndGame
    } view = View::MainMenu;

    void nextSeason();
    int getSeasonTime() const;
    std::string getSeasonString() const;
    std::pair<int, int> getCurrentQuestIds();

    void mainMenuView();
    void mainGameView();
    void newGameView();
    void questsView();
    void endGameView();

    void switchView(View newView);
    void setupGame();

public:
    Game(Renderer* renderer); //starts up game
    int getCoins() const;
    void run();
    void gameLoop();
};


#endif //GARDENERS_GAME_HPP
