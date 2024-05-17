#ifndef KMS_RENDERER_HPP
#define KMS_RENDERER_HPP

#include "SDL.h"
#include <string>
#include "SDL_ttf.h"

constexpr int windowWidth = 11 * 64 + 6 * 64;
constexpr int windowHeight = 11 * 64;

//class to wrap SDL rendering
class Renderer
{
public:

    Renderer(SDL_Renderer* r);

    //a texture which has a matching rectangle
    struct TextureWithRect
    {
        SDL_Texture * tex = nullptr;
        SDL_Rect rect {};

        ~TextureWithRect();
    };
    //renders the given texture
    void render(TextureWithRect& txr);
    //renders the given rexture at X and Y coordinates
    void render(TextureWithRect& txr, int x, int y);
    //draws an SDL texture with a custom rectangle
    void drawTexture(SDL_Texture* texture, SDL_Rect rect);

    //fills rectangle with a color
    void fillRect(const SDL_Rect& rect, SDL_Color c);
    //draws colored rectangle
    void drawRect(const SDL_Rect& rect, SDL_Color c);

    //sets custom drawing color
    void setColor(SDL_Color color);
    //clears screen with cutom color
    void clearScreen(SDL_Color color);

    //renders to the screen
    void present();

    //creates a line of text with custom font and color
    void createLineOfText(const std::string& string, TextureWithRect * txr, TTF_Font * font, SDL_Color c);

    //returns the renderer
    SDL_Renderer* getSDLRenderer();
private:
    SDL_Renderer* r;
};

#endif //KMS_RENDERER_HPP
