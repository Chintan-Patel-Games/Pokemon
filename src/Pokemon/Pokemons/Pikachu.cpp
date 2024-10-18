#include "../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, {Move("THUNDER SHOCK", 25), Move("TACKLE", 10)}) {}

        void Pikachu::Attack(Move selectedMove, Pokemon *target)
        {
            if (selectedMove.name == "THUNDER BOLT")
            {
                // 80% chance to hit
                if (rand() % 100 < 80)
                {
                    Pokemon::Attack(selectedMove, target);
                    std::cout << "... and it hit successfully!\n";
                }
                else
                    std::cout << "... but it missed!\n";
            }
            else
                Pokemon::Attack(selectedMove, target);
        }
    }
}