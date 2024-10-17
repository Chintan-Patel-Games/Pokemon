#pragma once
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/Grass.hpp"

namespace N_Main
{
    class Game
    {
    private:
        N_Pokemon::Grass forestGrass;

    public:
        Game();
        void GameLoop(N_Player::Player &player);
        void VisitPokeCenter(N_Player::Player &player);
    };
}