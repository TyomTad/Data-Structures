#ifndef __INT__
#define __INT__
#include "type.h"
#include "includes.h"
extern std::vector<std::vector<std::string>> memory;

class Int :public Type
{
public:
    Int(std::string name, std::string value);
public:
   // std::string addin(std::string,std::string) override;
   // std::string subin(std::string,std::string) override;
   // std::string divin(std::string,std::string) override;
   // std::string mulin(std::string,std::string) override;

   // static Int& getobject(const std::string &name, const std::string &value);
//private:
  //  static Int* objptr;

};

#endif
