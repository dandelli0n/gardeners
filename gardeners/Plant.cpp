//
// Created by Vikiii on 14/05/2023.
//

#include "Plant.hpp"
#include <fstream>
#include <utility>
#include <iostream>


Plant::Plant() : duration(0)
{ }


Plant::Plant(std::string n, int time, std::vector<ShapeAndMaker> shapesAndMakers) : name(std::move(n)), shapesAndMakers(std::move(shapesAndMakers)), duration(time)
{}

Shape& Plant::getShape()
{
    return shapesAndMakers[selection].s;
}

int Plant::getDuration()
{
    return duration;
}

std::vector<Plant> Plant::loadPlants()
{
    enum class Mode
    {
        KeywordSearch, DefinitionSearch, NameDataSearch, TypeDataSearch, ShapeDataSearch, TimeDataSearch
    } currentMode = Mode::DefinitionSearch;

    std::vector<Plant> plants;
    std::ifstream plantsFile("files/plants.txt");

    std::string nextWord;

    std::string nameData;

    std::vector<std::string> shapeData;
    std::vector<std::string> typeData;

    std::string dataStream;

    int timeData = 0;

    while(plantsFile >> nextWord)
    {
        if (nextWord == "EndOfPlantDefinition")
        {
            std::vector<ShapeAndMaker> shapesAndMakers;
            shapesAndMakers.reserve(shapeData.size());

            for (int i = 0; i < shapeData.size(); i++)
            {
                shapesAndMakers.push_back({TerrainTile::getMakerForType(typeData[i]), Shape(shapeData[i])});
            }

            plants.emplace_back(nameData, timeData, shapesAndMakers);

            shapeData.clear();
            typeData.clear();

            currentMode = Mode::DefinitionSearch;
        }

        switch (currentMode)
        {
            case Mode::KeywordSearch:

                dataStream.clear();
                if (nextWord == "name")
                    currentMode = Mode::NameDataSearch;

                if (nextWord == "shape")
                    currentMode = Mode::ShapeDataSearch;

                if (nextWord == "type")
                    currentMode = Mode::TypeDataSearch;

                if (nextWord == "time")
                    currentMode = Mode::TimeDataSearch;

                if (currentMode == Mode::KeywordSearch)
                    std::cout << "Unexpected keyword in plants.txt! \"" << nextWord << "\"\n";

                break;

            case Mode::DefinitionSearch:

                if (nextWord == "PlantDefinition")
                    currentMode = Mode::KeywordSearch;

                break;

            case Mode::NameDataSearch:
                dataStream.append(" " + nextWord);

                if (dataStream[dataStream.size() - 1] == '"')
                {
                    nameData = dataStream.substr(2, dataStream.size() - 3);
                    currentMode = Mode::KeywordSearch;
                }

                break;

            case Mode::TypeDataSearch:

                typeData.push_back(nextWord);
                currentMode = Mode::KeywordSearch;
                break;

            case Mode::ShapeDataSearch:
                shapeData.push_back(nextWord);
                currentMode = Mode::KeywordSearch;
                break;

            case Mode::TimeDataSearch:
                timeData = std::stoi(nextWord);
                currentMode = Mode::KeywordSearch;
                break;
        }
    }

    return plants;
}

std::unique_ptr<Tile> Plant::getNewTile()
{
    return shapesAndMakers[selection].tileMaker();
}

void Plant::nextSelection()
{
    selection++;
    selection %= shapesAndMakers.size();
}

Shape Plant::getCurrentShape()
{
    return shapesAndMakers[selection].s;
}

void Plant::previousSelection()
{
    selection--;
    if (selection < 0)
        selection = shapesAndMakers.size() - 1;
}

std::string Plant::getName() const
{
    return name;
}


