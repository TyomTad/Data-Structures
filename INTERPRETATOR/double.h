#ifndef __DOUBLE__
#define __DOUBLE__
#include "type.h"
#include "includes.h"

extern std::vector<std::vector<std::string>> memory;

class Double :public Type
{
public:
  Double(std::string name,std::string value);
  //std::string addin(std::string,std::string) override;
  //std::string subin(std::string,std::string) override;
  //std::string divin(std::string,std::string) override;
  //std::string mulin(std::string,std::string) override;


};


#endif
