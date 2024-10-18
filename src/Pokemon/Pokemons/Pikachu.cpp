#include "../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 20) {}

        void Pikachu::Attack(Pokemon* target)
        {
            ThunderShock(target);
        }

        void Pikachu::ThunderShock(Pokemon* target)
        {
            std::cout << name << " used THUNDER SHOCK!";
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