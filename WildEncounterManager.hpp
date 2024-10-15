#include <vector>
#include "Grass.hpp" // Assuming the Grass struct is defined here

class WildEncounterManager
{
public:
    WildEncounterManager();
    WildPokemon getRandomPokemonFromGrass(const Grass &grass);
};