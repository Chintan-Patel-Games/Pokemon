#include "../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Bug, 100, 10) {}

        void Caterpie::BugBite(Pokemon* target)
        {
            std::cout << name << " uses Bug Bite on " << target->name << "!\n";
            target->TakeDamage(20);
        }
    }
}