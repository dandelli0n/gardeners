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
    bool topRowEmty();
    void shiftLeft();
    void shiftUp();

public:
    Shape();
    Shape(const std::string& shapeString);
    bool& at(int x, int y);
    bool at(int x, int y) const;
    void setAt(int x, int y, int val);
    Shape& operator=(const Shape&);
    void align();
    void rotate();
    void mirror();
    //void copy();
};


#endif //GARDENERS_SHAPE_HPP
