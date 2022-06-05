#ifndef __CURSOR_INCLUDE_FILE__
#define __CURSOR_INCLUDE_FILE__

#include "Block.hpp"

class Cursor final : public Block
{
public:
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right
    };

public:
    Cursor();
    ~Cursor() = default;

public:
    void setX(int x);
    int getX() const;

    void setY(int y);
    int getY() const;

    void setPosition(int x, int y);
    void move(Direction direction);

    void setIsActive(bool isActive);
    bool isActive() const;

private:
    int _x = 0;
    int _y = 0;
    bool _isActive = true;
};

#endif // __CURSOR_INCLUDE_FILE__
