#include "Player.hpp"

#include <stdio.h>
#include <conio.h>

void Player::setMovedCursorCallback(const MovedCursorCallback& callback)
{
    _movedCursorCallback = callback;
}

void Player::setSettedCallback(const SettedCallback& callback)
{
    _settedCallback = callback;
}

void Player::setBlockState(Block::State blockState)
{
    _blockState = blockState;
}

Block::State Player::getBlockState() const
{
    return _blockState;
}

Block::State Player::getReverseBlockState() const
{
    switch (_blockState) {
        case Block::State::Cross: return Block::State::Zero;
        case Block::State::Zero: return Block::State::Cross;
    }
    return Block::State::Empty;
}

void Player::input()
{
    if (kbhit()) {
        char keyboard = _getch();

        if (keyboard == 72) {
            onMovedCursor(Cursor::Direction::Up);
        } else if (keyboard == 80) {
            onMovedCursor(Cursor::Direction::Down);
        } else if (keyboard == 75) {
            onMovedCursor(Cursor::Direction::Left);
        } else if (keyboard == 77) {
            onMovedCursor(Cursor::Direction::Right);
        } else if (keyboard == 13) {
            if (_settedCallback) {
                _settedCallback();
            }
        }
    }
}

void Player::onMovedCursor(Cursor::Direction direction)
{
    if (_movedCursorCallback) {
        _movedCursorCallback(direction);
    }
}
