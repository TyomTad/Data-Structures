#ifndef __CELL__
#define __CELL__
#include <iostream>

class Cell
{
private:
    std::string storage;

public:
    operator int();
    operator double();
    operator std::string();
    const Cell& operator=(const Cell& rhv);
    const Cell& operator=(Cell&& rhv);
    Cell();
    Cell(int n);
    Cell(double d);
    Cell(std::string str);
    Cell(Cell&& rhv);
    Cell(const Cell& rhv);
    ~Cell();
    std::string get_val();
    friend std::istream& operator>>(std::istream& inp, Cell& rhv);
};

std::ostream& operator<<(std::ostream& out, Cell& rhv);
std::istream& operator>>(std::istream& inp, Cell& rhv);

#include "Cell.cpp"
#endif
