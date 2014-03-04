#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <string>
#include "tttrules.h"
#include "game.h"
#include "inputvalidator.h"
#include "iplayer.h"
#include "uidriver.h"
#include "iplayerfactory.h"
#include "playerfactory.h"

class TTTEngine {
    
public:
    
    TTTEngine(UIDriver *driver, IPlayerFactory *factory){
        driver_ = driver;
        factory_ = factory;
    }
    
    void StartGame();
    IPlayer * CreatePlayer(std::string, std::string);
    
private:
    UIDriver *driver_;
    IPlayerFactory *factory_;
};
#endif
