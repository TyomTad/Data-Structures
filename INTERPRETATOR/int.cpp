#include "int.h"
#include "includes.h"
#include <vector>

extern std::vector<std::vector<std::string>> memory;

Int::Int(std::string name, std::string value) 
{
    std::vector<std::string> data = {name, value, "int"};
    memory.push_back(data);
}








