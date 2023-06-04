#ifndef GARDENERS_TASK_HPP
#define GARDENERS_TASK_HPP

#include "Board.hpp"
#include <string>
#include <cstdlib>


#include <unordered_map>
typedef std::function<int(Game &, Board &)> questType;

class QuestNameMapper
{
    static std::unordered_map<std::string, questType> questMapping;

public:
    QuestNameMapper(questType quest, const std::string& name);

    static questType find(const std::string& questName);


};

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

    static std::vector<Task> loadTasks();

    int evaluate(Game& game, Board& board);
    std::string getName();
    std::string getDesc();
    std::string getId();


};


#endif //GARDENERS_TASK_HPP
