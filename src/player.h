#ifndef TTT___player_h
#define TTT___player_h
#include <iostream>

class Player {

public:
    Player(std::string token) {
        token_ = token;
    };
    
    std::string token();
    
private:
    std::string token_;
};

#endif