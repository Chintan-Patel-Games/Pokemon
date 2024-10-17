#include "../include/Battle/WildEncounterManager.hpp"
#include "../include/Pokemon/Grass.hpp"
#include "../include/Pokemon/Pokemon.hpp"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

namespace N_Battle
{
    WildEncounterManager::WildEncounterManager()
    {
        srand(time(0)); // Seed the random number generator
    }

    N_Pokemon::Pokemon WildEncounterManager::GetRandomPokemonFromGrass(const N_Pokemon::Grass &grass)
    {
        int randomIndex = rand() % grass.wildPokemonList.size();
        return *grass.wildPokemonList[randomIndex];
    }
}