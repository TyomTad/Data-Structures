#ifndef _SPREADSHEET_
#define _SPREADSHEET_
#include "Cell.h"

class SpreadSheet
{
  private:
    Cell** arr;
    size_t row;
    size_t col;
  private:

    struct HAM
    {
      size_t x;
      size_t y;
    }obj;
    
  public:
    SpreadSheet();
    SpreadSheet(size_t n);
    SpreadSheet(size_t row,size_t col);
    ~SpreadSheet();
    Cell& operator[](HAM obj);
    const SpreadSheet& operator=(const SpreadSheet& rhv);
    const SpreadSheet& operator=(SpreadSheet&& rhv);

  public:
    size_t get_row();
    size_t get_col();
    void add_row(size_t row,size_t col, std::string str);
    void add_col(size_t row,size_t col, std::string str);
    void resize_row(size_t row);
    void resize_col(size_t col);
    void delete_row(size_t drow);
    void delete_col(size_t dcol);
    void copy_from(size_t newrow,size_t newcol , const SpreadSheet& rhv);
    
};

std::ostream& operator<<(std::ostream& out,SpreadSheet& rhv);
std::istream& operator>>(std::istream& in,SpreadSheet& rhv);

#include "SpreadSheet.cpp"
#endif //_SPREADSHEET_
