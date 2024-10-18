#pragma once
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/Grass.hpp"

namespace N_Main
{
    using namespace N_Character::N_Player;
    using namespace N_Pokemon;
    
    class Game
    {
    private:
        Grass forestGrass;

    public:
        Game();
        void GameLoop(N_Character::N_Player::Player* player);
        void VisitPokeCenter(N_Character::N_Player::Player* player);
    };
}