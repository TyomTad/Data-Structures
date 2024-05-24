#include "bool.h"
#include "includes.h"
#include <vector>

extern std::vector<std::vector<std::string>> memory;

Bool::Bool(std::string(name),std::string(value))
{
  std::vector<std::string> data = {name , value , "bool"} ;
  memory.push_back(data);
  
}

