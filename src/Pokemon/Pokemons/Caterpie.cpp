#include "../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Bug, 100, {Move("BUG BITE", 25), Move("TACKLE", 10)}) {}

        void Caterpie::Attack(Move selectedMove, Pokemon *target)
        {
            Pokemon::Attack(selectedMove, target);

            if (selectedMove.name == "STICKY WEB")
            {
                // Reduce the target's next attack damage (for simplicity, reducing by a fixed value)
                int reducedDamage = 5;
                target->Pokemon::ReduceAttackPower(reducedDamage, target);
                std::cout << target->name << "'s next attack will be reduced by " << reducedDamage << " damage!\n";
            }
        }
    }
}