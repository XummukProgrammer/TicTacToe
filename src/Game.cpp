#include "Game.hpp"

Game::Game()
    : _logic(this, _field, _player, _enemy)
{
}

void Game::setPlayerBlockState(Block::State state)
{
    _player.setBlockState(state);
    _enemy.setBlockState(_player.getReverseBlockState());
}

void Game::exec()
{
    _field.reset();
    _field.draw();

    while (!isGameOver() && !isGameWin()) {
        switch (_opponentTurn) {
            case OpponentTurn::Player:
                _player.input();
                break;

            case OpponentTurn::Enemy:
                _enemy.input();
                break;
        }
    }
}

void Game::onGameOver()
{
    _isGameOver = true;
}

bool Game::isGameOver() const
{
    return _isGameOver;
}

void Game::onGameWin()
{
    _isGameWin = true;
}

bool Game::isGameWin() const
{
    return _isGameWin;
}

void Game::toggleOpponent()
{
    if (_opponentTurn == OpponentTurn::Player) {
        _opponentTurn = OpponentTurn::Enemy;
    } else if (_opponentTurn == OpponentTurn::Enemy) {
        _opponentTurn = OpponentTurn::Player;
    }
}
