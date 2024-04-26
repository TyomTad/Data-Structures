#include "Cell.h"
#include <iostream>

Cell::operator int()
{
  return std::stoi(storage);
}

Cell::operator double()
{
  return std::stod(storage);
}

Cell::operator std::string()
{
  return static_cast<Cell>(storage);
}

const Cell& Cell::operator=(const Cell& rhv)
{
  if(this != &rhv)
  {
    storage = rhv.storage;
  }
  return *this;
}

const Cell& Cell::operator=(Cell&& rhv)
{
  if(this != &rhv)
  {
    storage = std::move(rhv.storage);
  }
  return *this;
}

Cell::Cell()
:storage{}
{}

Cell::Cell(int n)
{
  storage = n;
}

Cell::Cell(double n)
{
  storage = n;
}

Cell::Cell(std::string string)
{
  storage = string;
}

Cell::Cell(Cell&& rhv)
{
  storage = std::move(rhv.storage);
}

Cell::Cell(const Cell& rhv)
{
  storage = rhv.storage;
}

Cell::~Cell()
{}

std::string Cell::get_val()
{
  return storage;
}

std::ostream& operator<<(std::ostream& out, Cell& rhv)
{
  out << rhv.get_val();
  return out;
}

std::istream& operator>>(std::istream& in, Cell& rhv)
{
  in >> rhv.storage;
  return in;
}
