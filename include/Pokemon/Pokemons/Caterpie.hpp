#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Caterpie : public Pokemon
        {
        private:
            void BugBite(Pokemon* &target);
        public:
            Caterpie();
        };
    }
}