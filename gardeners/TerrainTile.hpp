#include "NonTerrainTile.hpp"

#ifndef GARDENERS_TERRAINTILE_HPP
#define GARDENERS_TERRAINTILE_HPP

#include <memory>
#include <functional>
#include <unordered_map>

class TerrainTile : public Tile
{
public:
    void draw(Renderer* r, int x, int y) override;

    std::string getName() const override;

    TerrainTile(std::string nameString, const std::string& resourceName);
    ~TerrainTile();

    static std::function<std::unique_ptr<Tile>()> getMakerForType(const std::string& typeName);
    static void registerMaker(std::function<std::unique_ptr<Tile>()>& func, const std::string& typeName);

private:
    std::string nameString = "None";
    static std::unordered_map<std::string, std::function<std::unique_ptr<Tile>()>> typeNameMakerMapping;
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = nullptr;

};

class TomatoTile : TerrainTile
{
public:
    static void registerMakerFunc();

private:
    TomatoTile();
    static std::unique_ptr<Tile> tomatoTileMaker();
};


class BeanTile : TerrainTile
{
public:
    static void registerMakerFunc();

private:
    BeanTile();
    static std::unique_ptr<Tile> beanTileMaker();
};


class SunflowerTile : TerrainTile
{
public:
    static void registerMakerFunc();

private:
    SunflowerTile();
    static std::unique_ptr<Tile> sunflowerTileMaker();
};


class LettuceTile : TerrainTile
{
public:
    static void registerMakerFunc();

private:
    LettuceTile();
    static std::unique_ptr<Tile> lettuceTileMaker();
};


#endif //GARDENERS_TERRAINTILE_HPP
