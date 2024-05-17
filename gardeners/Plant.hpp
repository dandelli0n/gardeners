#ifndef GARDENERS_PLANT_HPP
#define GARDENERS_PLANT_HPP

#include "Tile.hpp"
#include "TerrainTile.hpp"
#include "Shape.hpp"

#include <functional>
#include <vector>

//plant that you can place on the board
class Plant
{
public:

    struct ShapeAndMaker
    {
        //function that makes the plant tiles with the shape
        std::function<std::unique_ptr<Tile>()> tileMaker;
        //shape of plant tiles
        Shape s;
    };

private:
    std::string name;
    int duration;

    int selection = 0;
    std::vector<ShapeAndMaker> shapesAndMakers;

public:

    //makes new tile
    std::unique_ptr<Tile> getNewTile();
    //returns the name of the current plant
    std::string getName() const;

    //gets shape of plant
    Shape getCurrentShape();
    //jumps to next available selection, if it reached the end of available selections, it jumps back at 0
    void nextSelection();
    //goes to next available selection, if it reaches the beginning of available selections, it jumps to the end
    void previousSelection();

    //makes empty plant
    Plant();
    //makes plant that has name, duration and a shape
    Plant(std::string n, int time, std::vector<ShapeAndMaker> shapesAndMakers);

    //loads up all the plant cards to store from a txt
    static std::vector<Plant> loadPlants();

    //gets shape of plant as reference
    Shape& getShape();
    //returns plant's duration
    int getDuration();

    //void align(); these things are better done in shape class I think
};


#endif //GARDENERS_PLANT_HPP
