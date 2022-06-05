#ifndef __PLAYER_INCLUDE_FILE__
#define __PLAYER_INCLUDE_FILE__

#include "Block.hpp"
#include "Cursor.hpp"

#include <functional>

class Player final
{
public:
    using MovedCursorCallback = std::function<void(Cursor::Direction direction)>;
    using SettedCallback = std::function<void()>;

public:
    Player() = default;
    ~Player() = default;

public:
    void setMovedCursorCallback(const MovedCursorCallback& callback);
    void setSettedCallback(const SettedCallback& callback);

    void setBlockState(Block::State blockState);
    Block::State getBlockState() const;
    Block::State getReverseBlockState() const;

    void input();

private:
    void onMovedCursor(Cursor::Direction direction);

private:
    Block::State _blockState;
    MovedCursorCallback _movedCursorCallback;
    SettedCallback _settedCallback;
};

#endif // __PLAYER_INCLUDE_FILE__
