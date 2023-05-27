//
// Created by Vikiii on 14/05/2023.
//

#ifndef GARDENERS_SHAPE_HPP
#define GARDENERS_SHAPE_HPP

#include <vector>
#include <memory>
#include "Tile.hpp"
#include "TerrainTile.hpp"

class Shape
{
    bool shape[16];
    bool left_col_empty();
    bool top_row_emty();
    void shift_left();
    void shift_up();

public:
    Shape();
    Shape(const bool* t);
    bool& at(int x, int y);
    bool at(int x, int y) const;
    void set_at(int x, int y, int val);
    Shape& operator=(const Shape&);
    void align();
    void rotate();
    void mirror();
    void copy();
};


#endif //GARDENERS_SHAPE_HPP
