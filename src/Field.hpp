#ifndef __FIELD_INCLUDE_FILE__
#define __FIELD_INCLUDE_FILE__

#include "Block.hpp"

#include <functional>

class Field final
{
public:
    inline static const int MAX_WIDTH = 3;
    inline static const int MAX_HEIGHT = 3;

public:
    using ModifyBlockCallback = std::function<void(Block& block, const int x, const int y)>;
    using UpdateBlocksCallback = std::function<void()>;

public:
    Field() = default;
    ~Field() = default;

public:
    void setUpdateBlocksCallback(const UpdateBlocksCallback& callback);

    void setBlockState(int x, int y, Block::State state);
    bool isEqualBlockState(int x, int y, Block::State state) const;

    void reset();

    void draw();
    void update();

    static void gotoxy(const int x, const int y);

private:
    char getSymbolFromBlock(const Block& block);

    void modifyBlock(const ModifyBlockCallback& callback);

private:
    Block _blocks[MAX_HEIGHT][MAX_WIDTH];
    UpdateBlocksCallback _updateBlocksCallback;
};

#endif // __FIELD_INCLUDE_FILE__
