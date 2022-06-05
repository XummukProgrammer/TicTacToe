#include "Logic.hpp"

#include "Game.hpp"

Logic::Logic(Game* gamePtr, Field& field, Player& player)
    : _gamePtr(gamePtr)
    , _field(field)
    , _player(player)
{
    _field.setUpdateBlocksCallback(std::bind(&Logic::onBlocksUpdate, this));
    _player.setMovedCursorCallback(std::bind(&Logic::onPlayerMovedCursor, this, std::placeholders::_1));
    _player.setSettedCallback(std::bind(&Logic::onPlayerSetted, this));
}

void Logic::onPlayerMovedCursor(Cursor::Direction direction)
{
    auto& cursor = _field.getCursor();
    if (!cursor.isActive()) {
        return;
    }

    cursor.move(direction);
    _field.update();
}

void Logic::onPlayerSetted()
{
    auto& cursor = _field.getCursor();
    if (!cursor.isActive()) {
        return;
    }

    const int x = cursor.getX();
    const int y = cursor.getY();

    cursor.setIsActive(false);

    _field.setBlockState(x, y, _player.getBlockState());
    _field.update();
}

void Logic::onBlocksUpdate()
{
    const auto playerBlockState = _player.getBlockState();

    if (checkStateWithField(playerBlockState)) {
        _gamePtr->onGameOver();
    }
}

bool Logic::checkStateWithField(Block::State blockState) const
{
    return (_field.isEqualBlockState(0, 0, blockState) && _field.isEqualBlockState(1, 0, blockState) && _field.isEqualBlockState(2, 0, blockState))
        || (_field.isEqualBlockState(0, 1, blockState) && _field.isEqualBlockState(1, 1, blockState) && _field.isEqualBlockState(2, 1, blockState))
        || (_field.isEqualBlockState(0, 2, blockState) && _field.isEqualBlockState(1, 2, blockState) && _field.isEqualBlockState(2, 2, blockState))
        || (_field.isEqualBlockState(0, 0, blockState) && _field.isEqualBlockState(0, 1, blockState) && _field.isEqualBlockState(0, 2, blockState))
        || (_field.isEqualBlockState(1, 0, blockState) && _field.isEqualBlockState(1, 1, blockState) && _field.isEqualBlockState(1, 2, blockState))
        || (_field.isEqualBlockState(2, 0, blockState) && _field.isEqualBlockState(2, 1, blockState) && _field.isEqualBlockState(2, 2, blockState))
        || (_field.isEqualBlockState(0, 0, blockState) && _field.isEqualBlockState(1, 1, blockState) && _field.isEqualBlockState(2, 2, blockState))
        || (_field.isEqualBlockState(2, 0, blockState) && _field.isEqualBlockState(1, 1, blockState) && _field.isEqualBlockState(0, 2, blockState));
}
