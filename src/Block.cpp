#include "Block.hpp"

void Block::setState(State state)
{
    _state = state;
}

const Block::State& Block::getState() const
{
    return _state;
}
