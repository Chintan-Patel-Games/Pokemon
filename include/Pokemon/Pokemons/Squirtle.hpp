#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Squirtle : public Pokemon
        {
        public:
            Squirtle();
            void Attack(Pokemon* target) override;
            void WaterSplash(Pokemon* target);
        };
    }
}