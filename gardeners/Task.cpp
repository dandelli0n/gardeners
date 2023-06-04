//
// Created by Vikiii on 14/05/2023.
//

#include "Task.hpp"
#include <fstream>
#include <iostream>
#include <utility>
#include "Game.hpp"
#include <stdexcept>


std::unordered_map<std::string, questType> QuestNameMapper::questMapping;


std::string Task::getName()
{
    return name;
}

std::string Task::getDesc()
{
    return description;
}

std::string Task::getId()
{
    return id;
}

std::vector<Task> Task::loadTasks()
{
    std::vector<Task> tasks;

    std::ifstream f("quests.txt");

    std::string buf;

    std::string name;
    std::string description;
    std::string id;

    if(!f)
        throw "no such file";

    while (std::getline(f, buf))
    {
        name = buf;

        std::getline(f, buf);
        description = buf;


        std::getline(f, buf);
        id = buf;

        tasks.emplace_back(name, description, id);
    }

    return tasks;
}

Task::Task(std::string name, std::string description, std::string id) : name(std::move(name)), description(std::move(description)), id(std::move(id))
{
    questFn = QuestNameMapper::find(this->id);
}

int Task::evaluate(Game &game, Board &board)
{
    return questFn(game, board);
}

questType QuestNameMapper::find(const std::string &questName)
{
    if (questMapping.find(questName) == questMapping.end())
        throw std::out_of_range("Quest name out of range");

    return questMapping[questName];
}

QuestNameMapper::QuestNameMapper(questType quest, const std::string &name)
{
    questMapping[name] = quest;
}

QUEST_FUNC(tomato_quest)
{
    int count = 0;

    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if(board.getTileAt(j, i)->getName() == "Tomato")
                count++;
        }
    }
    return count;
}

QUEST_FUNC(lettuce_quest)
{
    int count = 0;

    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if(board.getTileAt(j, i)->getName() == "Lettuce")
                count++;
        }
    }
    return count;
}

QUEST_FUNC(bean_quest)
{
    int count = 0;

    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if(board.getTileAt(j, i)->getName() == "Bean")
                count++;
        }
    }
    return count;
}

QUEST_FUNC(sunflower_quest)
{
    int count = 0;

    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if(board.getTileAt(j, i)->getName() == "Sunflower")
                count++;
        }
    }
    return count;
}

QUEST_FUNC(rich_quest)
{
    return game.getCoins() * 2;
}

//eval fns



