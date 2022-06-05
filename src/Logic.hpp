#ifndef __LOGIC_INCLUDE_FILE__
#define __LOGIC_INCLUDE_FILE__

#include "Field.hpp"
#include "Player.hpp"

class Game;

class Logic final
{
public:
    Logic(Game* gamePtr, Field& field, Player& player);
    ~Logic() = default;

private:
    void onPlayerMoved(int x, int y);
    void onBlocksUpdate();

private:
    bool checkStateWithField(Block::State blockState) const;

private:
    Game* _gamePtr = nullptr;
    Field& _field;
    Player& _player;

};

#endif // __LOGIC_INCLUDE_FILE__
