#ifndef __TYPECONTROLER__
#define __TYPECONTROLER__
#include "includes.h"
#include "type.h"

extern std::vector<std::vector<std::string>> memory;

class TypeControler : public Type{
public:
  TypeControler(std::vector<std::string>);

  void chooseType(std::string,std::string);
private:
  std::string searchType(std::string);
  std::string Mathval(std::string,std::string,std::string);
  bool doub(std::string);
};


#endif
