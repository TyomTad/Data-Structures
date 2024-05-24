#include "string.h"
#include "includes.h"
#include <vector>

extern std::vector<std::vector<std::string>> memeory;

String::String(std::string name,  std::string value)
{
  std::vector<std::string> data = {name, value , "string"};
  memory.push_back(data);
};



