#include "../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 20) {}

        void Pikachu::ThunderShock(Pokemon* &target)
        {
            std::cout << name << " uses Thunder Shock on " << target->GetPokemonName() << "!\n";
            target->TakeDamage(20);
        }
    }
}