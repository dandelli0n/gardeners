#ifndef GARDENERS_BOARD_HPP
#define GARDENERS_BOARD_HPP

#include "Tile.hpp"
#include <vector>
#include <memory>
#include "Plant.hpp"
#include "Renderer.hpp"
#include <functional>

class Game;

class Board
{
private:
    int width = 11;
    int height = 11;
    std::vector<std::unique_ptr<Tile>> tiles;

    //cosmetics for rendering
    SDL_Surface* fenceSurface;
    SDL_Texture* fenceTexture = nullptr;

    void notifyTile(int x, int y, Tile* t);

public:
    Board();
    //gets board width
    int getW();
    //gets board height
    int getH();

    //gets number of collected coins through the game
    int getCoins() const;

    //clears board
    void clear();

    //draws board
    void draw(Renderer* r);
    //gets tile at set coordinates
    Tile* getTileAt(int x, int y);
    //sets tile to coordinates
    void setTile(int x, int y, std::unique_ptr<Tile> t);
    //checks if a plant can be placed to the set coordinates
    bool canPlacePlant(int x, int y, Plant& p);
    //places plant at coordinates
    bool placePlant(int x, int y, Plant& p);
};



#endif //GARDENERS_BOARD_HPP
