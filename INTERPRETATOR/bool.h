#ifndef __BOOL__
#define __BOOL__
#include "type.h"
#include "includes.h"
extern std::vector<std::vector<std::string>> memory;

class Bool :public Type
{
public:
  Bool(std::string name,std::string value);  
//  std::string addin(std::string,std::string) override;
//  std::string subin(std::string,std::string) override;
 // std::string divin(std::string,std::string) override;
  //std::string mulin(std::string,std::string) override;

};



#endif //__BOOL__
