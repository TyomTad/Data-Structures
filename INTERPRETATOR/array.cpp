#include "array.h"
#include "includes.h"
#include <vector>

extern std::vector<std::vector<std::string>> memory;

Array::Array(std::string(name),std::string(value))
{
  std::vector<std::string> data = {name , value , "array"};
  memory.push_back(data);
}

