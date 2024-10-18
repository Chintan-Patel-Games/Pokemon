#include "../include/Battle/BattleManager.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

namespace N_Battle
{
    using namespace std;
    using namespace N_Utility;
    using namespace N_Pokemon;

    void BattleManager::StartBattle(Player* player, N_Pokemon::Pokemon* wildPokemon)
    {
        battleState.playerPokemon = player->chosenPokemon;
        battleState.wildPokemon = wildPokemon;
        battleState.playerTurn = true; // Player starts first
        battleState.battleOngoing = true;

        cout << "A wild " << wildPokemon->name << " appeared!\n" << endl;
        Battle();
    }

    void BattleManager::StopBattle()
    {
        battleState.battleOngoing = false;
        HandleBattleOutcome();
    }

    void BattleManager::Battle()
    {
        while (battleState.battleOngoing)
        {
            if (battleState.playerTurn)
            {
                // Player's turn to attack
                battleState.playerPokemon->SelectAndUseMove(battleState.wildPokemon);
            }
            else
            {
                srand(time(0)); // Seed the random number generator
                int randomIndex = rand() % battleState.wildPokemon->moves.size();
                // Wild Pokémon's turn to attack
                battleState.wildPokemon->UseMove(battleState.wildPokemon->moves[randomIndex] , battleState.playerPokemon);
            }

            // Update the battle state after the turn
            UpdateBattleState();

            // Switch turns
            battleState.playerTurn = !battleState.playerTurn;

            N_Utility::Utility::WaitForEnter();
        }

        HandleBattleOutcome();
    }

    void BattleManager::UpdateBattleState()
    {
        if (battleState.playerPokemon->IsFainted())
        {
            battleState.battleOngoing = false;
        }
        else if (battleState.wildPokemon->IsFainted())
        {
            battleState.battleOngoing = false;
        }
    }

    void BattleManager::HandleBattleOutcome()
    {
        if (battleState.playerPokemon->IsFainted())
        {
            cout << battleState.playerPokemon->name << " has fainted! You lose the battle.\n";
        }
        else
        {
            cout << "You defeated the wild " << battleState.wildPokemon->name << "!\n";
        }
    }
}