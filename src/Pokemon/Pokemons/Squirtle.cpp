#include "../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 105, {Move("WATER SPLASH", 25), Move("TACKLE", 10), Move("RAPID SPIN", 5)}) {}

        void Squirtle::Attack(Move selectedMove, Pokemon *target)
        {
            Pokemon::Attack(selectedMove, target);

            if (selectedMove.name == "RAPID SPIN")
            {
                // Random number of hits between 2 and 5
                int hits = (rand() % 4) + 2;

                // Split damage across hits
                for (int i = 0; i < hits; ++i)
                {
                    Pokemon::Attack(selectedMove, target);
                }

                std::cout << "... and hit " << hits << " times!\\n";
            }
        }
    }
}