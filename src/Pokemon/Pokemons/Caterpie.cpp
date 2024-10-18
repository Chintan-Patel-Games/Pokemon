#include "../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Bug, 100, 10) {}

        void Caterpie::Attack(Pokemon* target)
        {
            BugBite(target);
        }

        void Caterpie::BugBite(Pokemon* target)
        {
            std::cout << name << " used BUG BITE!";
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