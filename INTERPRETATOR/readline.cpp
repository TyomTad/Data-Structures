#include "readline.h"
#include "typecontroler.h"
#include "ete.h"
//#include "includes.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

std::vector<std::string> tokens;
std::stack<char> scops;
std::unordered_map<size_t,std::string> myfile;


readline::readline(const std::string& str) {
  resolfile(str);
}

void readline::resolfile(std::string filename) {
  std::ifstream inputfile(filename);
  if (!inputfile.is_open()) {
    throw std::runtime_error("File could not be opened");
  }
  int k = 0;  
  std::string tmp;
  while (getline(inputfile, myfile[k])) {
    ++k;
  }

  for(int i = 0 ; i < myfile.size(); ++i){
    tokenizing(myfile[i]);      
  }
  inputfile.close();
}

void readline::tokenizing(std::string& line) {
  int found = line.find('=');
  std::string tmp;
  if (found != std::string::npos) {
    tmp = line.substr(0, found);
    tmp += " = " + line.substr(found + 1);
    line = tmp;
  }

  std::istringstream code(line);
    while (code >> tmp) {
      tokens.push_back(tmp);
    }
    
  if (!tokens.empty() && tokens[0] == "si") {
    for (size_t i = 0; i < tokens.size(); ++i) {
      if (tokens[i] == "(") {
        for (size_t j = i + 1; j < tokens.size(); ++j) {
          if (tokens[j] != ")" && tokens[j] != "{") {
            tokens.push_back(tokens[j]);
          } else {
            break;
          }
        }
      }
    }
  /*  if (!tokens.empty()) {
      ete ob;
      if (ob.Pay(etepay)) {
        etepay.clear();
        if (tokens.back() == "{") {
          ifbool = true;
          elsebool = false;
        } else {
          throw std::out_of_range("ete's open_scope is absent");
        }
      } else { }
    }*/
    tokens.clear();
  }


  
  processTokens();
  tokens.clear();
}

void readline::processTokens() {
  if (!tokens.empty()) {
    TypeControler tc(tokens);
  }
}

bool readline::elseif(std::string tmp){  
  std::string chlp;
  std::istringstream code(tmp);
  while(code >> chlp){
      if(chlp == "sino"){  
        return true;
      }
  }
  return false;
}
