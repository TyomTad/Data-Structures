#ifndef __ARRAY__
#define __ARRAY__
#include "type.h"
#include "includes.h"
extern std::vector<std::vector<std::string>> memory;

class Array :public Type
{
public:
  Array(std::string name,std::string value);
};


#endif
