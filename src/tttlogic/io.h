
#ifndef __TTT____io__
#define __TTT____io__

#include <string>

class IO{
    
public:
    
    virtual std::string GetInput()=0;
    virtual void Print(std::string)=0;
};

#endif