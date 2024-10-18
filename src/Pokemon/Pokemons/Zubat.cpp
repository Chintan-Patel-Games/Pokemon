#include "../include/Pokemon/Pokemons/Zubat.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Zubat::Zubat() : Pokemon("Zubat", PokemonType::Poison, 100, 20) {}

        void Zubat::Attack(Pokemon* target)
        {
            Supersonic(target);
        }

        void Zubat::Supersonic(Pokemon* target)
        {
            std::cout << name << " used SUERSONIC!";
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