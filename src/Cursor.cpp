#include "Cursor.hpp"

#include "Field.hpp"

Cursor::Cursor()
{
    setState(Block::State::Cursor);
}

void Cursor::setX(int x)
{
    _x = x;
}

int Cursor::getX() const
{
    return _x;
}

void Cursor::setY(int y)
{
    _y = y;
}

int Cursor::getY() const
{
    return _y;
}

void Cursor::setPosition(int x, int y)
{
    setX(x);
    setY(y);
}

void Cursor::move(Direction direction)
{
    switch (direction) {
        case Direction::Up: {
            if (_y > 0) {
                --_y;
            }
        } break;

        case Direction::Down: {
            if (_y < Field::MAX_HEIGHT - 1) {
                ++_y;
            }
        } break;

        case Direction::Left: {
            if (_x > 0) {
                --_x;
            }
        } break;

        case Direction::Right: {
            if (_x < Field::MAX_WIDTH - 1) {
                ++_x;
            }
        } break;
    }
}

void Cursor::setIsActive(bool isActive)
{
    _isActive = isActive;
}

bool Cursor::isActive() const
{
    return _isActive;
}
