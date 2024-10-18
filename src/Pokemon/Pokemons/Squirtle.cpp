#include "../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 100, 35) {}

        void Squirtle::WaterSplash(Pokemon* &target)
        {
            std::cout << name << " uses Water splash on " << target->GetPokemonName() << "!\n";
            target->TakeDamage(20);
        }
    }
}