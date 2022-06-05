#ifndef __BLOCK_INCLUDE_FILE__
#define __BLOCK_INCLUDE_FILE__

class Block final
{
public:
    enum class State
    {
        Empty,
        Cross,
        Zero
    };

public:
    Block() = default;
    ~Block() = default;

public:
    void setState(State state);
    const State& getState() const;

private:
    State _state;
};

#endif // __BLOCK_INCLUDE_FILE__
