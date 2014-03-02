#include "terminalio.h"
#include "playerfactory.h"
#include "tttengine.h"

int main(int argc, const char * argv[])
{
    IPlayerFactory *factory = new PlayerFactory();
    IO *io = new TerminalIO();
    TTTEngine engine = *new TTTEngine(io, factory);
    engine.StartGame();
    return 0;
}