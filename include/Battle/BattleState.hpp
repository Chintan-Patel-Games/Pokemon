#pragma once
#include "../include/Pokemon/Pokemon.hpp"

namespace N_Battle
{
    struct BattleState
    {
        N_Pokemon::Pokemon* playerPokemon = nullptr;
        N_Pokemon::Pokemon* wildPokemon = nullptr;
        bool playerTurn;        // True if it's the player's turn, false otherwise
        bool battleOngoing;     // True if the battle is still ongoing

        ~BattleState()
        {
            delete playerPokemon; // Free the memory allocated for playerPokemon
            delete wildPokemon;   // Free the memory allocated for wildPokemon
        }
    };
}