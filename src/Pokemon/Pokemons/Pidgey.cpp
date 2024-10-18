#include "../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pidgey::Pidgey() : Pokemon("Pidgey", PokemonType::Normal, 100, 35) {}

        void Pidgey::Attack(Pokemon *target)
        {
            WingAttack(target);
        }

        void Pidgey::WingAttack(Pokemon *target)
        {
            std::cout << name << " used WING ATTACK!";
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