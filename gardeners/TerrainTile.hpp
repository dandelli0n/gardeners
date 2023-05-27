#include "NonTerrainTile.hpp"

#ifndef GARDENERS_TERRAINTILE_HPP
#define GARDENERS_TERRAINTILE_HPP


class TerrainTile : public Tile
{
public:
    enum class Type
    {
        TOMATO, LETTUCE, BEAN, SUNFLOWER //void type is for error handling, if the class is created with a bigger number than the numbers of it gets void type
    };
    static Type string_to_type(const std::string& s);

private:
    Type type;

public:
    //TerrainTile();
    TerrainTile(Type t);
    void set_type(Type t);
    Type get_type();
    bool isOpen(){return false;}
    void draw() override;
    std::string getName() override;
    //~TerrainTile();

};


#endif //GARDENERS_TERRAINTILE_HPP
