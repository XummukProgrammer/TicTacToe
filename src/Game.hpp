#ifndef __GAME_INCLUDE_FILE__
#define __GAME_INCLUDE_FILE__

#include "Logic.hpp"
#include "Field.hpp"
#include "Player.hpp"

class Game final
{
public:
    Game();
    ~Game() = default;

public:
    void setPlayerBlockState(Block::State state);

    void exec();

    void setIsGameOver(bool isGameOver);
    bool isGameOver() const;

private:
    bool _isGameOver = false;
    Field _field;
    Player _player;
    Logic _logic;
};

#endif // __GAME_INCLUDE_FILE__
