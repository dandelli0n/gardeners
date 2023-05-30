#ifndef GARDENERS_TASK_HPP
#define GARDENERS_TASK_HPP

#include "Board.hpp"
#include <string>
#include <cstdlib>


#include <unordered_map>
typedef std::function<int(Game &, Board &)> quest_type;

class QuestNameMapper
{
    static std::unordered_map<std::string, quest_type> quest_mapping;

public:
    QuestNameMapper(quest_type quest, const std::string& name);

    static quest_type find(const std::string& quest_name);


};

#define QUEST_FUNC(function_name) int function_name (Game&, Board&); static QuestNameMapper qmapper ##function_name (function_name, #function_name); int function_name (Game& game, Board& board)




class Task {
    std::string name;
    std::string description;
    std::string id;
    static std::vector<Task> tasks;
    static bool tasks_loaded;
    static void load_tasks();
    quest_type quest_fn;

    Task(std::string name, std::string description, std::string id);
public:
    Task(); //also loads from file so there is no need for loadfromfile function
    //int evaluate(Board board);
    std::string get_name();
    std::string get_desc();
    std::string get_id();


};


#endif //GARDENERS_TASK_HPP
