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
            void WaterSplash(Pokemon* target);
        };
    }
}