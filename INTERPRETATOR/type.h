#ifndef __TYPE__
#define __TYPE__

#include "includes.h"

class Type 
{
public:   

    std::string name;
    std::string value;
    std::string type;
//    virtual std::string addin(std::string,std::string);    
//    virtual std::string subin(std::string,std::string);    
//    virtual std::string divin(std::string,std::string);    
//    virtual std::string mulin(std::string,std::string);
    
    virtual ~Type();
};



#endif
