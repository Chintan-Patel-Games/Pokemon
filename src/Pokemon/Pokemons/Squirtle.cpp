#include "../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 100, 35) {}

        void Squirtle::Attack(Pokemon* target)
        {
            WaterSplash(target);
        }

        void Squirtle::WaterSplash(Pokemon* target)
        {
            std::cout << name << " used WATER SPLASH!";
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