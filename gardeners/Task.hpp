#ifndef GARDENERS_TASK_HPP
#define GARDENERS_TASK_HPP

#include "Board.hpp"
#include <string>
#include <cstdlib>


class Task {
    std::string name;
    std::string description;
    std::string id;
    static std::vector<Task> tasks;
    static bool tasks_loaded;
    static void load_tasks();
    quests::type quest_fn;

    Task(std::string name, std::string description, std::string id);
public:
    Task(); //also loads from file so there is no need for loadfromfile function
    //int evaluate(Board board);
    std::string get_name();
    std::string get_desc();
    std::string get_id();


};


#endif //GARDENERS_TASK_HPP
