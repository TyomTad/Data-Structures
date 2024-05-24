#ifndef __STRING__
#define __STRING__
#include "type.h"
#include "includes.h"
extern std::vector<std::vector<std::string>> memory;

class String :public Type
{
public: 
  String(std::string name,std::string value);  
  //std::string addin(std::string,std::string) override;
  //std::string subin(std::string,std::string) override;
  //std::string divin(std::string,std::string) override;
  //std::string mulin(std::string,std::string) override;

};

#endif
