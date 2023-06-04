//
// Created by Vikiii on 14/05/2023.
//

#include "Board.hpp"
#include "NonTerrainTile.hpp"
#include <iostream>



Board::Board()
{
    fenceSurface = SDL_LoadBMP("files/sprites/fence.bmp");

    clear();
}

/*void Board::setTile(std::unique_ptr<Tile> t, int x, int y)
{
    tiles[x + width * y] = std::move(t);
}*/

void Board::draw(Renderer* r)
{
    if (fenceTexture == nullptr)
        fenceTexture = SDL_CreateTextureFromSurface(r->getSDLRenderer(), fenceSurface);

    for (int x = 0; x < Board::width; ++x)
    {
        for (int y = 0; y < Board::height; ++y)
        {
            tiles[x + width*y]->draw(r, x * 64, y * 64);
        }
    }

    SDL_Rect fenceRect;
    fenceRect.x = Board::width * 64;
    fenceRect.w = 64;
    fenceRect.h = 64;


    for (int i = 0; i < Board::height; ++i)
    {
        fenceRect.y = i * 64;
        r->drawTexture(fenceTexture, fenceRect);
    }
}

void Board::setTile(int x, int y, std::unique_ptr<Tile> t)
{
    notifyTile(x + 1, y, t.get());
    notifyTile(x, y + 1, t.get());

    notifyTile(x, y - 1, t.get());
    notifyTile(x - 1, y, t.get());


    tiles[(y*width) + x] = std::move(t);
}

int Board::getW()
{
    return width;
}

int Board::getH()
{
    return height;
}


bool Board::placePlant(int xt, int yt, Plant& p)
{
    if (!canPlacePlant(xt, yt, p))
        return false;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (p.getShape().at(x, y))
            {
                setTile(x + xt, y + yt, p.getNewTile());
            }
        }
    }

    return true;
}

Tile* Board::getTileAt(int x, int y)
{
    return tiles[x + (width * y)].get();
}

void Board::notifyTile(int x, int y, Tile *t)
{
    if (x >= 0 && x < width)
    {
        if (y >= 0 && y < height)
        {
            tiles[x + y * width]->newTilePlacedNext(t);
        }
    }
}

int Board::getCoins() const
{
    int count = 0;

    for (int i = 0; i < width * height; i++)
    {
        count += tiles[i]->worthPoints();
    }

    return count;
}

bool Board::canPlacePlant(int xt, int yt, Plant &p)
{
    Shape& plantShape = p.getShape();

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (p.getShape().at(x, y))
            {
                if(!(xt + x < 11 && xt + x >= 0) || !(yt + y < 11 && yt + y >= 0))
                    return false;

                if (!getTileAt(xt + x, yt + y)->isOpen())
                    return false;
            }
        }
    }

    return true;
}

void Board::clear()
{
    tiles.clear();
    for (int i = 0; i < width * height; ++i)
    {
        if ((i == 1*11+3) || (i == 2*11+8) || (i==5*11+5) || (i==8*11+2) || (i==9*11+7))
        {
            tiles.push_back(std::make_unique<LakeTile>());
        }
        else
        {
            tiles.push_back(std::make_unique<EmptyTile>());
        }
    }
}





