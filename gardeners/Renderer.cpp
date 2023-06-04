#include "Renderer.hpp"

void Renderer::createLineOfText(const std::string& string, TextureWithRect * txr, TTF_Font * font, SDL_Color c)
{
    SDL_Surface * surface = TTF_RenderText_Blended(font, string.c_str(), c);

    if (txr->tex != nullptr)
        SDL_DestroyTexture(txr->tex);

    txr->tex = SDL_CreateTextureFromSurface(r, surface);
    txr->rect.w = surface->w / 2;
    txr->rect.h = surface->h / 2;

    SDL_FreeSurface(surface);
}


void Renderer::setColor(SDL_Color color)
{
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
}

void Renderer::clearScreen(SDL_Color color)
{
    setColor(color);
    SDL_RenderClear(r);
}

Renderer::Renderer(SDL_Renderer *r) : r(r)
{
    SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
}

void Renderer::render(Renderer::TextureWithRect &txr)
{
    SDL_RenderCopy(r, txr.tex, NULL, &txr.rect);
}

void Renderer::render(Renderer::TextureWithRect &txr, int x, int y)
{
    int ox = txr.rect.x;
    int oy = txr.rect.y;
    txr.rect.x = x;
    txr.rect.y = y;

    render(txr);

    txr.rect.x = ox;
    txr.rect.y = oy;
}

void Renderer::present()
{
    SDL_RenderPresent(r);
}

void Renderer::fillRect(const SDL_Rect &rect, SDL_Color c)
{
    setColor(c);
    SDL_RenderFillRect(r, &rect);
}

void Renderer::drawRect(const SDL_Rect &rect, SDL_Color c)
{
    setColor(c);
    SDL_RenderDrawRect(r, &rect);
}

void Renderer::drawTexture(SDL_Texture *texture, SDL_Rect rect)
{
    SDL_RenderCopy(r, texture, NULL, &rect);
}

SDL_Renderer *Renderer::getSDLRenderer()
{
    return r;
}

Renderer::TextureWithRect::~TextureWithRect()
{
    SDL_DestroyTexture(tex);
}
