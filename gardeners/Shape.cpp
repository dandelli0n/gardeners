//
// Created by Vikiii on 14/05/2023.
//

#include "Shape.hpp"

Shape::Shape(const bool* t)
{
    for (int i = 0; i < 16; ++i)
    {
        shape[i] = t[i];
    }
}

Shape::Shape()
{
    for (int i = 0; i < 16; ++i)
    {
        shape[i] = false;
    }
}

void Shape::operator=(Shape& rhs)
{
    for (int i = 0; i < 16; ++i)
    {
        shape[i] = rhs.shape[i];
    }
}

bool &Shape::at(int x, int y)
{
    return shape[x + (y * 4)];
}

bool Shape::at(int x, int y) const
{
    return shape[x + (y * 4)];
}




