#pragma once
#include <vector>
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
    struct Grass;
    class Pokemon;
}

namespace N_Battle
{
    using namespace N_Pokemon;

    class WildEncounterManager
    {
    public:
        WildEncounterManager();
        N_Pokemon::Pokemon* GetRandomPokemonFromGrass(const Grass grass);
    };
}