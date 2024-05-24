#include "double.h"
#include "includes.h"
#include <vector>

extern std::vector<std::vector<std::string>> memory;

Double::Double(std::string(name),std::string(value))
{
  std::vector<std::string> data = {name , value, "double"};
  memory.push_back(data);  
}


