#ifndef TTT___boardinterface_h
#define TTT___boardinterface_h

#include <iostream>
#include "vector"

class BoardInterface {
    
public:
    
    virtual std::string Winner()=0;
    virtual std::vector<std::string> state()=0;
    virtual bool full()=0;
};


#endif
