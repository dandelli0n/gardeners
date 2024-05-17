#include "TerrainTile.hpp"

void TerrainTile::draw(Renderer *r, int x, int y)
{
    if (texture == nullptr)
        texture = SDL_CreateTextureFromSurface(r->getSDLRenderer(), surface);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    rect.w = 64;
    rect.h = 64;

    r->drawTexture(texture, rect);
}

std::string TerrainTile::getName() const
{
    return nameString;
}

TerrainTile::TerrainTile(std::string nameString, const std::string& resourceName) : nameString(std::move(nameString))
{
    surface = SDL_LoadBMP(std::string(resourceName).c_str());
}

std::unordered_map<std::string, std::function<std::unique_ptr<Tile>()>> TerrainTile::typeNameMakerMapping;
std::function<std::unique_ptr<Tile>()> TerrainTile::getMakerForType(const std::string &typeName)
{
    return typeNameMakerMapping[typeName];
}

void TerrainTile::registerMaker(std::function<std::unique_ptr<Tile>()> &func, const std::string& typeName)
{
    typeNameMakerMapping[typeName] = func;
}

TerrainTile::~TerrainTile()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

TomatoTile::TomatoTile() : TerrainTile("Tomato", "tomato.bmp")
{}

std::unique_ptr<Tile> TomatoTile::tomatoTileMaker()
{
    std::unique_ptr<Tile> tile(new TomatoTile);
    return std::move(tile);
}

void TomatoTile::registerMakerFunc()
{
    std::function<std::unique_ptr<Tile>()> f = tomatoTileMaker;
    TerrainTile::registerMaker(f, "Tomato");
}

BeanTile::BeanTile() : TerrainTile("Bean", "bean.bmp")
{}

void BeanTile::registerMakerFunc()
{
    std::function<std::unique_ptr<Tile>()> f = beanTileMaker;
    TerrainTile::registerMaker(f, "Bean");
}

std::unique_ptr<Tile> BeanTile::beanTileMaker()
{
    std::unique_ptr<Tile> tile(new BeanTile);
    return std::move(tile);
}

SunflowerTile::SunflowerTile() : TerrainTile("Sunflower", "sunflower.bmp")
{}

void SunflowerTile::registerMakerFunc()
{
    std::function<std::unique_ptr<Tile>()> f = sunflowerTileMaker;
    TerrainTile::registerMaker(f, "Sunflower");
}

std::unique_ptr<Tile> SunflowerTile::sunflowerTileMaker()
{
    std::unique_ptr<Tile> tile(new SunflowerTile);
    return std::move(tile);
}

LettuceTile::LettuceTile() : TerrainTile("Lettuce", "lettuce.bmp")
{}

void LettuceTile::registerMakerFunc()
{
    std::function<std::unique_ptr<Tile>()> f = lettuceTileMaker;
    TerrainTile::registerMaker(f, "Lettuce");
}

std::unique_ptr<Tile> LettuceTile::lettuceTileMaker()
{
    std::unique_ptr<Tile> tile(new LettuceTile);
    return std::move(tile);
}
