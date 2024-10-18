#include "../include/Pokemon/Pokemons/Charmander.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, {Move("FLAME THROWER", 25), Move("TACKLE", 10)}) {}

        void Charmander::Attack(Move selectedMove, Pokemon *target)
        {
            Pokemon::Attack(selectedMove, target);

            if (selectedMove.name == "BLAZING CHARGE")
            {
                // Recoil effect: Charmander takes recoil damage
                this->TakeDamage(10); // Fixed recoil damage
                std::cout << name << " takes 10 recoil damage from the Blazing Charge!\n";
                N_Utility::Utility::WaitForEnter();
            }
        }
    }
}