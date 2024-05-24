#ifndef __ETE__
#define __ETE__
#include "includes.h"
#include "bool.h"
#include "type.h"
#include "int.h"
#include "typecontroler.h"
#include "double.h"
#include "string.h"
#include "array.h"
#include "readline.h"

extern std::vector<std::vector<std::string>> memory;

class ete{
  std::string val1;
  std::string val2;
  std::string nshan;
public:
  //ete(std::vector<std::vector<std::string>> body);
  bool Pay(std::vector<std::string>);
  bool doub(const std::string&);
};



#endif //__ETE__
