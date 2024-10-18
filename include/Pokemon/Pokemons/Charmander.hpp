#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Charmander : public Pokemon
        {
        private:
            void FlameThrower(Pokemon* &target);

        public:
            Charmander();
        };
    }
}