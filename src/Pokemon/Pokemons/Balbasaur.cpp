#include "../include/Pokemon/Pokemons/Balbasaur.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Balbasaur::Balbasaur() : Pokemon("Balbasaur", PokemonType::Grass, 100, 35) {}

        void Balbasaur::VineWhip(Pokemon* target)
        {
            std::cout << name << " uses vine Whip on " << target->name << "!\n";
            target->TakeDamage(20);
        }
    }
}