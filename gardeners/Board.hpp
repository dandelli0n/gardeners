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

    SDL_Surface* fenceSurface;
    SDL_Texture* fenceTexture = nullptr;

    void notifyTile(int x, int y, Tile* t);

public:
    Board();
    int getW();
    int getH();

    int getCoins() const;

    void clear();

    void draw(Renderer* r);
    Tile* getTileAt(int x, int y);
    void setTile(int x, int y, std::unique_ptr<Tile> t);
    bool canPlacePlant(int x, int y, Plant& p);
    bool placePlant(int x, int y, Plant& p);
};



#endif //GARDENERS_BOARD_HPP
