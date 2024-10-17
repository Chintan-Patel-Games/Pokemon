#pragma once
#include <string>
#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Player
{
    class Player
    {
    public:
        std::string name;
        N_Pokemon::Pokemon chosenPokemon;

        Player();                                       // Default constructor
        Player(std::string p_name, N_Pokemon::Pokemon p_chosenPokemon); // Parameterized constructor

        void ChoosePokemon(int choice); // Method to choose a Pokemon
    };
}