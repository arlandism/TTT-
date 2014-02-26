#ifndef __TTT____mockboard__
#define __TTT____mockboard__

#include <iostream>
#include "boardinterface.h"

class MockBoard: public BoardInterface {
 
public:
    
    MockBoard(std::string winner, std::vector<std::string> state, bool full){
        winner_ = winner;
        state_ = state;
        full_ = full;
    }
    
    virtual std::string Winner()=0;
    virtual std::vector<std::string> state()=0;
    virtual bool full()=0;
    
private:
    std::string winner_;
    std::vector<std::string> state_;
    bool full_;
    
};
#endif