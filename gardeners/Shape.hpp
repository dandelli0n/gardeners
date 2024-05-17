//
// Created by Vikiii on 14/05/2023.
//

#ifndef GARDENERS_SHAPE_HPP
#define GARDENERS_SHAPE_HPP

#include <vector>
#include <array>
#include <memory>
#include "Tile.hpp"
#include "TerrainTile.hpp"

class Shape
{
    std::array<bool, 16> shape = {};
    bool leftColEmpty();
    bool topRowEmpty();
    void shiftLeft();
    void shiftUp();

public:
    //creates empty shape
    Shape();
    //creates shape based on a given string
    Shape(const std::string& shapeString);
    //gets value at X and Y - reference type
    bool& at(int x, int y);
    //gets value at X and Y - const type
    bool at(int x, int y) const;
    //sets value at coordinates
    void setAt(int x, int y, int val);
    //checks if the two shapes are the same
    Shape& operator=(const Shape&);
    //aligns shape to the top left corner of the 4x4 square
    void align();
    //rotates shape
    void rotate();
    //mirrors shape
    void mirror();
    //void copy();
};


#endif //GARDENERS_SHAPE_HPP
