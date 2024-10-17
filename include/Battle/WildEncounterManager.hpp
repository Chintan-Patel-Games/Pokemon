#pragma once
#include "../include/Pokemon/Pokemon.hpp"
#include "../include/Pokemon/Grass.hpp"
#include <vector>

namespace N_Battle
{
    class WildEncounterManager
    {
    public:
        WildEncounterManager();
        N_Pokemon::Pokemon GetRandomPokemonFromGrass(const N_Pokemon::Grass &grass);
    };
}