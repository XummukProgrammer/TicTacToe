#include <iostream>

#include "src/Game.hpp"

using namespace std;

int main()
{
    Game game;
    game.setPlayerBlockState(Block::State::Cross);
    game.exec();
    return 0;
}
