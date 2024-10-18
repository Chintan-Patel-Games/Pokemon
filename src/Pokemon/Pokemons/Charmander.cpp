#include "../include/Pokemon/Pokemons/Charmander.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, 35) {}

        void Charmander::Attack(Pokemon *target)
        {
            FlameThrower(target);
        }

        void Charmander::FlameThrower(Pokemon *target)
        {
            std::cout << name << " used FLAME THROWER!";
            N_Utility::Utility::WaitForEnter();

            std::cout << "...";
            N_Utility::Utility::WaitForEnter();

            target->TakeDamage(attackPower);

            if (target->IsFainted())
                std::cout << target->name << " fainted!";
            else
                std::cout << target->name << " has " << target->health << " HP left.";
            N_Utility::Utility::WaitForEnter();
        }
    }
}