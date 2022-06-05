#ifndef __BLOCK_INCLUDE_FILE__
#define __BLOCK_INCLUDE_FILE__

class Block
{
public:
    enum class State
    {
        Empty,
        Cross,
        Zero,
        Cursor
    };

public:
    Block() = default;
    virtual ~Block() = default;

public:
    void setState(State state);
    const State& getState() const;

    char getSymbol() const;

private:
    State _state;
};

#endif // __BLOCK_INCLUDE_FILE__
