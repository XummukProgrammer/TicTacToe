#include "Field.hpp"

#include <iostream>

#include <windows.h>

void Field::setBlockState(int x, int y, Block::State state)
{
    _blocks[y][x].setState(state);
}

bool Field::isEqualBlockState(int x, int y, Block::State state) const
{
    return _blocks[y][x].getState() == state;
}

void Field::setUpdateBlocksCallback(const UpdateBlocksCallback& callback)
{
    _updateBlocksCallback = callback;
}

Cursor& Field::getCursor()
{
    return _cursor;
}

void Field::reset()
{
    modifyBlock([](Block& block, const int x, const int y) {
        block.setState(Block::State::Empty);
    });
}

void Field::draw()
{
    modifyBlock([this](Block& block, const int x, const int y) {
        gotoxy(x, y);
        std::cout << block.getSymbol();
    });

    if (_cursor.isActive()) {
        gotoxy(_cursor.getX(), _cursor.getY());
        std::cout << _cursor.getSymbol();
    }

    gotoxy(0, MAX_HEIGHT);
}

void Field::update()
{
    for (int y = 0; y <= MAX_HEIGHT; ++y) {
        gotoxy(0, y);
        std::cout << "                 ";
    }

    draw();

    if (_updateBlocksCallback) {
        _updateBlocksCallback();
    }
}

void Field::modifyBlock(const ModifyBlockCallback& callback)
{
    if (!callback) {
        return;
    }

    for (int y = 0; y < MAX_HEIGHT; ++y) {
        for (int x = 0; x < MAX_WIDTH; ++x) {
            callback(_blocks[y][x], x, y);
        }
    }
}

void Field::gotoxy(const int x, const int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
