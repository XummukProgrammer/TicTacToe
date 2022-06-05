#include "Block.hpp"

void Block::setState(State state)
{
    _state = state;
}

const Block::State& Block::getState() const
{
    return _state;
}

char Block::getSymbol() const
{
    switch (getState()) {
        case Block::State::Empty: return '.';
        case Block::State::Cross: return 'X';
        case Block::State::Zero: return '0';
        case Block::State::Cursor: return '#';
    }
    return 'E';
}
