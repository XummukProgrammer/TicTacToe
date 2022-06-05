#include "Player.hpp"

#include <stdio.h>
#include <conio.h>

#include <iostream>

void Player::setMovedCallback(const MovedCallback& callback)
{
    _movedCallback = callback;
}

void Player::setBlockState(Block::State blockState)
{
    _blockState = blockState;
}

Block::State Player::getBlockState() const
{
    return _blockState;
}

void Player::input()
{
    if (kbhit()) {
        if (_movedCallback) {
            int x = 0, y = 0;
            std::cin >> x >> y;
            _movedCallback(x, y);
        }
    }
}
