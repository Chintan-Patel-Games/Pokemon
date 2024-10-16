#pragma once
#include "Grass.hpp"

class Player;

class Game
{
private:
    Grass forestGrass;

public:
    Game();
    void GameLoop(Player &player);
    void VisitPokeCenter(Player &player);
};