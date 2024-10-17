#include "../include/Pokemon/Pokemons/Zubat.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Zubat::Zubat() : Pokemon("Zubat", PokemonType::Poison, 100, 20) {}

        void Zubat::Supersonic(Pokemon &target)
        {
            std::cout << name << " uses Supersonic on " << target.GetPokemonName() << "!\n";
            target.TakeDamage(20);
        }
    }
}