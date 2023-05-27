//
// Created by Vikiii on 14/05/2023.
//

#include "Task.hpp"
#include <fstream>
#include <iostream>
#include <utility>


std::vector<Task> Task::tasks;
bool Task::tasks_loaded = false;

std::unordered_map<std::string, quest_type> QuestNameMapper::quest_mapping;

Task::Task()
{
    if (!tasks_loaded)
        load_tasks();

    int t_num = rand() % tasks.size(); //need to do something about duplications but rn i cant
    name = tasks.at(t_num).name;
    description = tasks.at(t_num).description;
    id = tasks.at(t_num).id;
    quest_fn = QuestNameMapper::find(id);
}

std::string Task::get_name()
{
    return name;
}

std::string Task::get_desc()
{
    return description;
}

std::string Task::get_id()
{
    return id;
}

void Task::load_tasks()
{
    std::ifstream f;
    f.open("quests.txt");
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

        tasks.push_back(Task(name, description, id));
    }
    f.close();

    tasks_loaded = true;
}

Task::Task(std::string name, std::string description, std::string id) : name(std::move(name)), description(std::move(description)), id(std::move(id))
{

}

quest_type QuestNameMapper::find(const std::string &quest_name)
{
    if (quest_mapping.find(quest_name) == quest_mapping.end())
        throw "aaaaaaaaaaa";

    return quest_mapping[quest_name];
}

QuestNameMapper::QuestNameMapper(quest_type quest, const std::string &name)
{
    quest_mapping[name] = quest;
}

QUEST_FUNC(tomato_quest)
{
    int count = 0;

    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if(board.get_tile_at(j, i)->getName() == "tomato")
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
            if(board.get_tile_at(j, i)->getName() == "lettuce")
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
            if(board.get_tile_at(j, i)->getName() == "bean")
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
            if(board.get_tile_at(j, i)->getName() == "sunflower")
                count++;
        }
    }
    return count;
}

QUEST_FUNC(rich_quest)
{
    return game.get_coins()*2;
}

//eval fns



