//
// Created by Vikiii on 14/05/2023.
//

#include "Shape.hpp"

void swapBool(bool* a, bool* b)
{
    bool t = *a;
    *a = *b;
    *b = t;
}

Shape::Shape(const std::string& shapeString)
{
    for (int i = 0; i < 16; ++i)
    {
        if (shapeString[i] == '#')
            shape[i] = true;
        else
            shape[i] = false;
    }
}

Shape::Shape()
{
    for (int i = 0; i < 16; ++i)
    {
        shape[i] = false;
    }
}

Shape& Shape::operator=(const Shape& rhs)
{
    for (int i = 0; i < 16; ++i)
    {
        shape[i] = rhs.shape[i];
    }

    return *this;
}

bool &Shape::at(int x, int y)
{
    return shape[x + (y * 4)];
}

bool Shape::at(int x, int y) const
{
    return shape[x + (y * 4)];
}

void Shape::setAt(int x, int y, int val)
{
    shape[x + (y*4)] = val;
}

bool Shape::leftColEmpty() {
    for (int i = 0; i < 4; ++i)
    {
        if(at(0, i))
            return false;
    }
    return true;
}

bool Shape::topRowEmty()
{
    for (int i = 0; i < 4; ++i)
    {
        if(at(i, 0))
            return false;
    }
    return true;
}

void Shape::shiftLeft()
{
    std::array<bool, 16> originalShape = shape;
    shape = {};
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            setAt(x, y, originalShape[(x+1) + y * 4]);
        }
    }
}

void Shape::shiftUp()
{
    std::array<bool, 16> originalShape = shape;
    shape = {};
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            setAt(x, y, originalShape[x + ((y+1) * 4)]);
        }
    }
}

void Shape::align()
{
    while(topRowEmty())
        shiftUp();

    while (leftColEmpty())
        shiftLeft();
}

void Shape::rotate()
{
    std::array<bool, 16> originalShape = shape;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            setAt(i, j, originalShape[j + i * 4]);
        }
    }

    originalShape = shape;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            setAt(i, j, originalShape[i + (4 - 1 - j) * 4]);
        }
    }

    align();
}





