#include <iostream>
#include "readline.h"
#include "includes.h"
#include <vector>
#include <string>

std::vector<std::vector<std::string>> memory;
std::vector<std::vector<std::string>> etebody;
int main()
{
  readline("text.txt");
   
  for(const auto& entry : memory){
    for(const auto& field : entry){
      std::cout << field << " ";
    }
    std::cout << std::endl;
  }    

  std::cout << "-----------------------------------" <<std::endl;
  for(const auto& entry : etebody){
    for(const auto& field : entry){
      std::cout << field << " ";
    }
      std::cout << std::endl;
  }    

  return 0;
}
