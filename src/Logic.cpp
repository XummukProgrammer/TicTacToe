#include "Logic.hpp"

#include "Game.hpp"

Logic::Logic(Game* gamePtr, Field& field, Player& player)
    : _gamePtr(gamePtr)
    , _field(field)
    , _player(player)
{
    _field.setUpdateBlocksCallback(std::bind(&Logic::onBlocksUpdate, this));
    _player.setMovedCallback(std::bind(&Logic::onPlayerMoved, this, std::placeholders::_1, std::placeholders::_2));
}

void Logic::onPlayerMoved(int x, int y)
{
    _field.setBlockState(x - 1, y - 1, _player.getBlockState());
    _field.update();
}

void Logic::onBlocksUpdate()
{
    const auto playerBlockState = _player.getBlockState();

    if (checkStateWithField(playerBlockState)) {
        _gamePtr->setIsGameOver(true);
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
