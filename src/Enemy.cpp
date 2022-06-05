#include "Enemy.hpp"

void Enemy::setSettedCallback(const SettedCallback& callback)
{
    _settedCallback = callback;
}

void Enemy::setBlockState(Block::State blockState)
{
    _blockState = blockState;
}

Block::State Enemy::getBlockState() const
{
    return _blockState;
}

void Enemy::input()
{
    if (_settedCallback) {
        _settedCallback();
    }
}
