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

void Shape::set_at(int x, int y, int val)
{
    shape[x + (y*4)] = val;
}

bool Shape::left_col_empty() {
    for (int i = 0; i < 4; ++i)
    {
        if(!this->at(0, i))
            return false;
    }
    return true;
}

bool Shape::top_row_emty()
{
    for (int i = 0; i < 4; ++i)
    {
        if(!this->at(i, 0))
            return false;
    }
    return true;
}

void Shape::shift_left()
{
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            set_at(x, y, this->at(x+1, y));
        }
    }
}

void Shape::shift_up()
{
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            set_at(x, y, this->at(x, y+1));
        }
    }
}

void Shape::align()
{
    while(top_row_emty())
        shift_up();

    while (left_col_empty())
        shift_left();
}





