#include "../include/Battle/BattleManager.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Battle
{
    using namespace std;
    using namespace N_Utility;

    void BattleManager::StartBattle(Player *&player, N_Pokemon::Pokemon *&wildPokemon)
    {
        // Allocate memory for battleState if it's not already allocated
        if (battleState == nullptr)
        {
            battleState = new BattleState; // Create a new BattleState object
        }

        battleState->playerPokemon = player->chosenPokemon;
        battleState->wildPokemon = wildPokemon;
        battleState->playerTurn = true; // Player starts first
        battleState->battleOngoing = true;

        cout << "A wild " << wildPokemon->GetPokemonName() << " appeared!\n";
        Battle();
    }

    void BattleManager::Battle()
    {
        while (battleState->battleOngoing)
        {
            if (battleState->playerTurn)
            {
                // Player's turn to attack
                battleState->playerPokemon->Attack(battleState->wildPokemon);
            }
            else
            {
                // Wild Pokémon's turn to attack
                battleState->wildPokemon->Attack(battleState->playerPokemon);
            }

            // Update the battle state after the turn
            UpdateBattleState();

            // Switch turns
            battleState->playerTurn = !battleState->playerTurn;

            N_Utility::Utility::WaitForEnter();
        }

        HandleBattleOutcome();
    }

    void BattleManager::UpdateBattleState()
    {
        if (battleState->playerPokemon->IsFainted())
        {
            battleState->battleOngoing = false;
        }
        else if (battleState->wildPokemon->IsFainted())
        {
            battleState->battleOngoing = false;
        }
    }

    void BattleManager::HandleBattleOutcome()
    {
        if (battleState->playerPokemon->IsFainted())
        {
            cout << battleState->playerPokemon->GetPokemonName() << " has fainted! You lose the battle.\n";
        }
        else
        {
            cout << "You defeated the wild " << battleState->wildPokemon->GetPokemonName() << "!\n";
        }
    }

    BattleManager::~BattleManager()
    {
        delete (battleState);
    }
}