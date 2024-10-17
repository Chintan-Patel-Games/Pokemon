#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Battle
{
    struct BattleState
    {
        N_Pokemon::Pokemon *playerPokemon; // Pointer to the player's Pokémon
        N_Pokemon::Pokemon *wildPokemon;   // Pointer to the wild Pokémon
        bool playerTurn;        // True if it's the player's turn, false otherwise
        bool battleOngoing;     // True if the battle is still ongoing
    };
}