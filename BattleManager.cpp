#include "BattleManager.hpp"
#include "Utility.hpp"
#include <iostream>
using namespace std;

void BattleManager::StartBattle(Player &player, Pokemon &wildPokemon)
{
    cout << "A wild " << wildPokemon.name << " appeared!" << endl;
    Utility::WaitForEnter();
    Battle(player.chosenPokemon, wildPokemon);
}

void BattleManager::Battle(Pokemon &playerPokemon, Pokemon &wildPokemon)
{
    while (!playerPokemon.IsFainted() && !wildPokemon.IsFainted())
    {
        // Player attacks first
        playerPokemon.Attack(wildPokemon);

        // Check if wild Pokémon fainted
        if (!wildPokemon.IsFainted())
        {
            // Wild Pokémon attacks back
            wildPokemon.Attack(playerPokemon);
        }

        // Pause to show the result of each turn
        Utility::WaitForEnter();
    }

    // Determine and display the outcome of the battle
    HandleBattleOutcome(playerPokemon, playerPokemon.IsFainted());
}

void BattleManager::HandleBattleOutcome(Pokemon &playerPokemon, bool playerLost)
{
    if (playerLost)
    {
        std::cout << "Oh no! " << playerPokemon.name << " fainted! You need to visit the PokeCenter.\n";
        Utility::WaitForEnter();
        std::cout << "Game Over.\n";
    }
    else
    {
        std::cout << playerPokemon.name << " is victorious! Keep an eye on your Pokémon's health.\n";
    }
}