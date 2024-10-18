#include "../include/Pokemon/Pokemons/Balbasaur.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Balbasaur::Balbasaur() : Pokemon("Balbasaur", PokemonType::Grass, 100, 35) {}

        void Balbasaur::Attack(Pokemon *target)
        {
            VineWhip(target);
        }

        void Balbasaur::VineWhip(Pokemon *target)
        {
            std::cout << name << " used VINE WHIP!";
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