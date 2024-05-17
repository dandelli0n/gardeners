#ifndef GARDENERS_TASK_HPP
#define GARDENERS_TASK_HPP

#include "Board.hpp"
#include <string>
#include <cstdlib>


#include <unordered_map>
typedef std::function<int(Game &, Board &)> questType;

//class to search quest's function by its name
class QuestNameMapper
{
    static std::unordered_map<std::string, questType> questMapping;

public:
    QuestNameMapper(questType quest, const std::string& name);

    static questType find(const std::string& questName);


};

//black magic, delete from skeleton
#define QUEST_FUNC(function_name) int function_name (Game&, Board&); static QuestNameMapper qmapper ##function_name (function_name, #function_name); int function_name (Game& game, Board& board)



class Task
{
    std::string name;
    std::string description;
    std::string id;
    questType questFn;

public:
    Task(std::string name, std::string description, std::string id);
    Task() = default;

    //loads up tasks from a file
    static std::vector<Task> loadTasks();

    //evaluates board based on the current game state and the current task
    int evaluate(Game& game, Board& board);
    //returns task name
    std::string getName();
    //returns task description
    std::string getDesc();
    //returns task ID
    std::string getId();


};


#endif //GARDENERS_TASK_HPP
