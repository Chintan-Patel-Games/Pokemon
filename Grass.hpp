// grass.hpp
#include "PokemonType.hpp"
#include "Pokemon.hpp"
#include <string>
#include <vector>
using namespace std;
using WildPokemon = Pokemon;

struct Grass
{
    string environmentType;              // Example: "Forest", "Cave", "Riverbank"
    vector<WildPokemon> wildPokemonList; // List of wild Pokémon that live in this grass
    int encounterRate;                   // Likelihood of encountering a wild Pokémon, out of 100
};

Grass forestGrass = {
    "Forest",
    {
        {"Zubat", PokemonType::Poison, 30},
        {"Caterpie", PokemonType::Bug, 35},
        {"Pidgey", PokemonType::Normal, 40}
    },
    80
};

Grass caveGrass = {
    "Cave",
    {
        {"Geodude", PokemonType::Rock, 50}
    },
    70
};