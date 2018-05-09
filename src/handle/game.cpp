#include "game.h"
#include "game_impl.h"

Game::Game() : game_impl(new GameImpl()) {}

Game::Game(const Game &rhs) : game_impl(new GameImpl(*rhs.game_impl)) {}
Game &Game::operator=(const Game &rhs)
{
    *game_impl = *rhs.game_impl;
    return *this;
}

Game::~Game() = default;

void Game::gameLoop()
{
    game_impl->GameLoop();
}

bool Game::HandleInput(const char &input)
{
    return game_impl->HandleInput(input);
}
