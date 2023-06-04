#ifndef GARDENERS_PLANT_HPP
#define GARDENERS_PLANT_HPP

#include "Tile.hpp"
#include "TerrainTile.hpp"
#include "Shape.hpp"

#include <functional>
#include <vector>

class Plant
{
public:
    struct ShapeAndMaker
    {
        std::function<std::unique_ptr<Tile>()> tileMaker;
        Shape s;
    };

private:
    std::string name;
    int duration;

    int selection = 0;

    std::vector<ShapeAndMaker> shapesAndMakers;

public:
    std::unique_ptr<Tile> getNewTile();
    std::string getName() const;

    Shape getCurrentShape();
    void nextSelection();
    void previousSelection();

    Plant();
    Plant(std::string n, int time, std::vector<ShapeAndMaker> shapesAndMakers);

    static std::vector<Plant> loadPlants();
    Shape& getShape();
    int getDuration();

    //void align(); these things are better done in shape class I think
};


#endif //GARDENERS_PLANT_HPP
