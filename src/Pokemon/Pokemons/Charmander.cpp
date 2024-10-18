#include "../include/Pokemon/Pokemons/Charmander.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, 35) {}

        void Charmander::FlameThrower(Pokemon* target)
        {
            std::cout << name << " uses Flame Thrower on " << target->name << "!\n";
            target->TakeDamage(20);
        }
    }
}