#include "Tile.hpp"

#ifndef GARDENERS_NONTERRAINTILE_HPP
#define GARDENERS_NONTERRAINTILE_HPP


class NonTerrainTile : public Tile
{
public:
    enum class Type
    {
        LAKE, EMPTY
    };

private:
    Type type;

public:
    NonTerrainTile(Type a);
    void draw() override;
    bool isOpen() override;
    std::string getName() override;
    ~NonTerrainTile();
};


#endif //GARDENERS_NONTERRAINTILE_HPP
