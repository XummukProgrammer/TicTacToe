#ifndef __FIELD_INCLUDE_FILE__
#define __FIELD_INCLUDE_FILE__

#include "Block.hpp"
#include "Cursor.hpp"

#include <functional>

class Field final
{
public:
    inline static const int MAX_WIDTH = 3;
    inline static const int MAX_HEIGHT = 3;

public:
    using ModifyBlockCallback = std::function<void(Block& block, const int x, const int y)>;

public:
    Field() = default;
    ~Field() = default;

public:
    void setBlockState(int x, int y, Block::State state);
    bool isEqualBlockState(int x, int y, Block::State state) const;

    Cursor& getCursor();

    void reset();

    void draw();
    void update();

    static void gotoxy(const int x, const int y);

private:
    void modifyBlock(const ModifyBlockCallback& callback);

private:
    Block _blocks[MAX_HEIGHT][MAX_WIDTH];
    Cursor _cursor;
};

#endif // __FIELD_INCLUDE_FILE__
