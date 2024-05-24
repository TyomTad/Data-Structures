#ifndef __READLINE__
#define __READLINE__
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class readline {
public:
  explicit readline (const std::string&);
  void resolfile(std::string);  
  void tokenizing(std::string&);
  void processTokens();
  bool elseif(std::string);
  void ifik(int);
  
};


#endif // __READLINE__
