#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        class Zubat : public Pokemon
        {
        private:
            void Supersonic(Pokemon* &target);
        public:
            Zubat();
        };
    }
}