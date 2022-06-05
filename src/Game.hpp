#ifndef __GAME_INCLUDE_FILE__
#define __GAME_INCLUDE_FILE__

#include "Logic.hpp"
#include "Field.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#include <functional>

class Game final
{
public:
    enum class OpponentTurn
    {
        Player,
        Enemy
    };

public:
    Game();
    ~Game() = default;

public:
    void setPlayerBlockState(Block::State state);

    void exec();

    void onGameOver();
    bool isGameOver() const;

    void onGameWin();
    bool isGameWin() const;

    void toggleOpponent();

private:
    bool _isGameOver = false;
    bool _isGameWin = false;
    Field _field;
    Player _player;
    Enemy _enemy;
    Logic _logic;
    OpponentTurn _opponentTurn = OpponentTurn::Player;
};

#endif // __GAME_INCLUDE_FILE__
