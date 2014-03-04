#ifndef __TTT____game__
#define __TTT____game__

#include <string>
#include "iplayer.h"
#include "tttrules.h"

class Game {
    
public:
    
    Game(Board *board, IPlayer *player_one, IPlayer *player_two){
        board_ = board;
        player_one_ = player_one;
        player_two_ = player_two;
    };
    void Round();
    
private:
    
    Board *board_;
    IPlayer *player_one_;
    IPlayer *player_two_;
    
    void PlayerMove(IPlayer *);
};
#endif