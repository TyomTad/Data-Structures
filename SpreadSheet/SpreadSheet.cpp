#include "SpreadSheet.h"

SpreadSheet::SpreadSheet()
  :arr{nullptr}
  ,row{0}
  ,col{0}
{}

SpreadSheet::SpreadSheet(size_t n)
  :arr{new Cell*[n]}
  ,row{0}
  ,col{0}
{
  for(size_t i = 0; i < n ; ++i)
  {
    arr[i] = new Cell[n];
  }
}

SpreadSheet::SpreadSheet(size_t row,size_t col)
  :arr(new Cell*[row])
  ,row(row)
  ,col(col)
{
  for(size_t i = 0; i < col; ++i){
    arr[i] = new Cell[col];
  }
  
}

SpreadSheet::~SpreadSheet()
{
  for(size_t i = 0; i < row; ++i)
  {
    delete[] arr[i];
  }
  delete[] arr;
}

Cell& SpreadSheet::operator[](HAM obj)
{
  return arr[obj.x][obj.y];
}

const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv)
{
  if(this != &rhv)
  {
    for(size_t i = 0;i < row; ++i){
      delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    arr = new Cell*[rhv.row];
    for(size_t i = 0;i < rhv.row; ++i)
    {
      arr[i] = new Cell[rhv.col];
    }

    for(size_t i = 0; i < rhv.row;++i)
    {
      for(size_t j = 0 ; j < rhv.col; ++j)
      {
        arr[i][j] = rhv.arr[i][j];
      }
    }

    row = rhv.row;
    col = rhv.col;
    
  }
  return *this;
} 


const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv)
{
  if(this != &rhv)
  {
    for(size_t i = 0; i < row; ++i)
    {
      delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    arr = new Cell*[rhv.row];

    for(size_t i = 0 ; i < rhv.row; ++i)
    {
      arr[i] = new Cell[rhv.col];
      for(size_t j = 0; j < col; ++j)
      {
        arr[i][j] = std::move(rhv.arr[i][j]);
      }
    }

    for(size_t i = 0; i < row; ++i)
    {
      delete[] rhv.arr[i];
    }
    row = rhv.row;
    col = rhv.col;
    delete[] rhv.arr;
  }
  return *this;
}

void SpreadSheet::add_row(size_t row,size_t col, std::string str)
{
  arr[row][col] = str;
}

void SpreadSheet::add_col(size_t row,size_t col,std::string str)
{
  this->arr[row][col] = str; 
}

void SpreadSheet::resize_row(size_t row)
{
  Cell** new_arr = new Cell*[this->row+row];
  for(size_t i = 0;i < this->row + row; ++i)
  {
    new_arr[i] = new Cell[this->col];
  }

  for(size_t i = 0 ; i < this->row; ++i)
  {
    for(size_t j = 0; j < this->col; ++i)
    {
      new_arr[i][j] = arr[i][j];
    }
  }

  for(size_t i = 0; i < this->row; ++i)
  {
    delete[] arr[i];
  }
  delete[] arr;
  arr = nullptr;
  arr = new_arr;
  this->row += row; 
}

void SpreadSheet::resize_col(size_t col)
{
    Cell** new_arr = new Cell*[this->row];
    for (size_t i = 0; i < this->row; i++)
    {
        new_arr[i] = new Cell[this->col + col];
    }

    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; i++) {
            new_arr[i][j] = arr[i][j];
        }
        
    }
    
    for (size_t i = 0; i < this->row; i++)
    {
        delete[] arr[i];
    }
    
    delete[] arr;
    arr = nullptr;
    arr = new_arr;
    this->col += col;
}

void SpreadSheet::delete_row(size_t del_row)
{
    if (del_row > this->row) {
        throw 1;
    }
    
    for (size_t i = 0; i < row; i++)
    {
        if (i == del_row)
        {
           delete[] arr[i];
           arr[i] = nullptr;
           for (size_t i = del_row; i < row - 1; i++)
           {
                arr[i] = arr[i + 1];
           }
            
        }
        
    }
    --this->row;

}

void SpreadSheet::delete_col(size_t del_col)
{
    if (del_col > this->col) {
        throw 1;
    }

    for (size_t i = 0; i < row; i++) 
      {
        for (size_t j = 0; j < col; j++) 
          {
            if (j == del_col)
              {   
                for (size_t v = del_col; v < col - 1; v++) 
                {
                  arr[i][v] = arr[i][v + 1];
                }            
              }
          }   
      }
    --this->col;
}

void SpreadSheet::copy_from(size_t oth_row, size_t oth_col, const SpreadSheet& rhv)
{   
    if (oth_row > row || oth_col > col)
    {
        throw 1;
    }
    
    Cell** new_arr = new Cell*[oth_row];
    for (size_t i = 0; i < oth_row; ++i) {
        new_arr[i] = new Cell[oth_col];
    }
    for(size_t i = 0; i < oth_row; ++i) {
        for(size_t j = 0; j < oth_col; ++j) {
            
            arr[i][j] = rhv.arr[i][j];
    
        }
    }
    
    
}

size_t SpreadSheet::get_row()
{
    return row;
}

size_t SpreadSheet::get_col()
{
    return col;
}

std::ostream& operator<<(std::ostream& out, SpreadSheet& rhv)
{   
    for (size_t i = 0; i < rhv.get_row(); i++) {
        for (size_t j = 0; j < rhv.get_col(); j++)
        {
            out << rhv[{i, j}];
        }
        
    }
    return out;
    
}

std::istream& operator>>(std::istream& in, SpreadSheet& rhv)
{
    for (size_t i = 0; i < rhv.get_row(); i++) {
        for (size_t j = 0; j < rhv.get_col(); j++)
        {
            in >> rhv[{i, j}];
        }
        
    }
    return in;
}
