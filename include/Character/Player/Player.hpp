#pragma once
#include <string>
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Character
{
    namespace N_Player
    {
        using namespace N_Pokemon;

        class Player
        {
        public:
            std::string name;
            Pokemon *chosenPokemon;

            Player(); // Default constructor
            Player(std::string p_name); // Parameterized constructor

            void ChoosePokemon(int choice); // Method to choose a Pokemon
        };
    }
}