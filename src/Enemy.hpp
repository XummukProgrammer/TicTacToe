#ifndef __ENEMY_INCLUDE_FILE__
#define __ENEMY_INCLUDE_FILE__

#include "Block.hpp"

#include <functional>

class Enemy final
{
public:
    using SettedCallback = std::function<void()>;

public:
    Enemy() = default;
    ~Enemy() = default;

public:
    void setSettedCallback(const SettedCallback& callback);

    void setBlockState(Block::State blockState);
    Block::State getBlockState() const;

    void input();

private:
    Block::State _blockState;
    SettedCallback _settedCallback;
};

#endif // __ENEMY_INCLUDE_FILE__
