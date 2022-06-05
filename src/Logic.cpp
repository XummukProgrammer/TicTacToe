#include "Logic.hpp"

#include "Game.hpp"

Logic::Logic(Game* gamePtr, Field& field, Player& player, Enemy& enemy)
    : _gamePtr(gamePtr)
    , _field(field)
    , _player(player)
    , _enemy(enemy)
{
    _player.setMovedCursorCallback(std::bind(&Logic::onPlayerMovedCursor, this, std::placeholders::_1));
    _player.setSettedCallback(std::bind(&Logic::onPlayerSetted, this));
    _enemy.setSettedCallback(std::bind(&Logic::onEnemySetted, this));
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

    if (!_field.isEqualBlockState(x, y, Block::State::Empty)) {
        return;
    }

    cursor.setIsActive(false);

    _field.setBlockState(x, y, _player.getBlockState());
    _field.update();

    _gamePtr->toggleOpponent();

    if (checkStateWithField(_player.getBlockState())) {
        _gamePtr->onGameWin();
    }
}

void Logic::onEnemySetted()
{
    _field.getCursor().setIsActive(true);
    _field.update();

    _gamePtr->toggleOpponent();

    if (checkStateWithField(_enemy.getBlockState())) {
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
