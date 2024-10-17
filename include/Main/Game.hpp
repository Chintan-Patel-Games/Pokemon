#pragma once
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/Grass.hpp"

namespace N_Main
{
    using namespace N_Pokemon;
    using namespace N_Character::N_Player;
    
    class Game
    {
    private:
        Grass forestGrass;

    public:
        Game();
        void GameLoop(Player &player);
        void VisitPokeCenter(Player &player);
    };
}