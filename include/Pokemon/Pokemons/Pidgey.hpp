#pragma once
#include "../include/Pokemon/Pokemon.hpp"
#include "../include/Battle/BattleManager.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Pidgey : public Pokemon
        {
        public:
            Pidgey();
            N_Battle::BattleManager* battleManager;
            void Attack(Move selectedMove, Pokemon* target) override;
        };
    }
}