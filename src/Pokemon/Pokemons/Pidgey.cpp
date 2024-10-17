#include "../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pidgey::Pidgey() : Pokemon("Pidgey", PokemonType::Normal, 100, 35) {}

        void Pidgey::WingAttack(Pokemon &target)
        {
            std::cout << name << " uses Wing Attack on " << target.name << "!\n";
            target.TakeDamage(20);
        }
    }
}