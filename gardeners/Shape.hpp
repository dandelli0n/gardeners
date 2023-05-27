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

public:
    Shape();
    Shape(const bool* t);

    bool& at(int x, int y);
    bool at(int x, int y) const;
    void operator=(Shape&);
};


#endif //GARDENERS_SHAPE_HPP
