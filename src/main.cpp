#include "terminalio.h"
#include "playerfactory.h"
#include "tttengine.h"
#include "uidriver.h"

int main(int argc, const char * argv[])
{
    IPlayerFactory *factory = new PlayerFactory();
    IO *io = new TerminalIO();
    UIDriver *driver = new UIDriver(io, factory);
    TTTEngine engine = *new TTTEngine(driver);
    engine.StartGame();
    return 0;
}