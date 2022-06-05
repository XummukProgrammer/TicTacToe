#ifndef __LOGIC_INCLUDE_FILE__
#define __LOGIC_INCLUDE_FILE__

#include "Field.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game;

class Logic final
{
public:
    Logic(Game* gamePtr, Field& field, Player& player, Enemy& enemy);
    ~Logic() = default;

private:
    void onPlayerMovedCursor(Cursor::Direction direction);
    void onPlayerSetted();
    void onEnemySetted();

private:
    bool checkStateWithField(Block::State blockState) const;

private:
    Game* _gamePtr = nullptr;
    Field& _field;
    Player& _player;
    Enemy& _enemy;

};

#endif // __LOGIC_INCLUDE_FILE__
