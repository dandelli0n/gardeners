//
// Created by Vikiii on 14/05/2023.
//

#include "Task.hpp"
#include <fstream>
#include <iostream>
#include <utility>


std::vector<Task> Task::tasks;
bool Task::tasks_loaded = false;


Task::Task()
{
    if (!tasks_loaded)
        load_tasks();

    int t_num = rand() % tasks.size(); //need to do something about duplications but rn i cant
    name = tasks.at(t_num).name;
    description = tasks.at(t_num).description;
    id = tasks.at(t_num).id;
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

//eval fns



