#include "terminalio.h"
#include "tttengine.h"

int main(int argc, const char * argv[])
{
    IO *io = new TerminalIO();
    TTTEngine engine = *new TTTEngine(io);
    engine.StartGame();
    return 0;
}