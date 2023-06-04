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

#undef main
int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();


    SDL_Window* window = SDL_CreateWindow("Gardeners", 50, 50, windowWidth, windowHeight, NULL);

    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, NULL, NULL);
    auto renderer = std::make_unique<Renderer>(sdlRenderer);

    Game game(renderer.get());

    game.run();



    return 0;
}
