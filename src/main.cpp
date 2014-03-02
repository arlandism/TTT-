#include "tttengine.h"

int main(int argc, const char * argv[])
{
    TTTEngine engine = *new TTTEngine();
    engine.StartGame();
    return 0;
}