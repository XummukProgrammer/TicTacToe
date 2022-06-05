#ifndef __PLAYER_INCLUDE_FILE__
#define __PLAYER_INCLUDE_FILE__

#include "Block.hpp"

#include <functional>

class Player final
{
public:
    using MovedCallback = std::function<void(int x, int y)>;

public:
    Player() = default;
    ~Player() = default;

public:
    void setMovedCallback(const MovedCallback& callback);

    void setBlockState(Block::State blockState);
    Block::State getBlockState() const;

    void input();

private:
    Block::State _blockState;
    MovedCallback _movedCallback;
};

#endif // __PLAYER_INCLUDE_FILE__
