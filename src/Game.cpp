#include "Game.hpp"

Game::Game()
    : _logic(this, _field, _player)
{
}

void Game::setPlayerBlockState(Block::State state)
{
    _player.setBlockState(state);
}

void Game::exec()
{
    _field.reset();
    _field.draw();

    while (!isGameOver()) {
        _player.input();
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
