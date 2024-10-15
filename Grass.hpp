#ifndef GRASS_HPP
#define GRASS_HPP

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

#endif // GRASS_HPP