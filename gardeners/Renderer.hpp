#ifndef GARDENERS_RENDERER_HPP
#define GARDENERS_RENDERER_HPP

#include "SDL.h"
#include <string>
#include "SDL_ttf.h"

constexpr int windowWidth = 11 * 64 + 6 * 64;
constexpr int windowHeight = 11 * 64;


class Renderer
{
public:
    Renderer(SDL_Renderer* r);

    struct TextureWithRect
    {
        SDL_Texture * tex = nullptr;
        SDL_Rect rect {};

        ~TextureWithRect();
    };

    void render(TextureWithRect& txr);
    void render(TextureWithRect& txr, int x, int y);

    void drawTexture(SDL_Texture* texture, SDL_Rect rect);

    void fillRect(const SDL_Rect& rect, SDL_Color c);
    void drawRect(const SDL_Rect& rect, SDL_Color c);

    void setColor(SDL_Color color);
    void clearScreen(SDL_Color color);

    void present();

    void createLineOfText(const std::string& string, TextureWithRect * txr, TTF_Font * font, SDL_Color c);

    SDL_Renderer* getSDLRenderer();
private:
    SDL_Renderer* r;
};

#endif //GARDENERS_RENDERER_HPP
