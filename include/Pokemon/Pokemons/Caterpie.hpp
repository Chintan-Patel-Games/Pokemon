#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Caterpie : public Pokemon
        {
        public:
            Caterpie();
            void BugBite(Pokemon &target);
        };
    }
}