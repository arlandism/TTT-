#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <string>
#include "uipresenter.h"
#include "tttrules.h"
#include "game.h"
#include "inputvalidator.h"
#include "iplayer.h"
#include "uidriver.h"
#include "playerfactory.h"

class TTTEngine {
    
public:
    
    TTTEngine(UIDriver *driver){
        driver_ = driver;
    }
    
    void StartGame();
    
private:
    UIDriver *driver_;
    std::vector<std::string> valid_token_choices = {"x", "o"};
};
#endif
