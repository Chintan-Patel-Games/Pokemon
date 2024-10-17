#include "../include/Main/Game.hpp"
#include "../include/Battle/BattleManager.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include "../include/Battle/WildEncounterManager.hpp"
#include <iostream>
using namespace std;

namespace N_Main
{
    Game::Game() : forestGrass{"Forest",
                               {new N_Pokemon::Pokemon("Pidgey", N_Pokemon::PokemonType::Normal, 40, 7),
                                new N_Pokemon::Pokemon("Caterpie", N_Pokemon::PokemonType::Bug, 35, 5),
                                new N_Pokemon::Pokemon("Zubat", N_Pokemon::PokemonType::Poison, 30, 8)},
                               70}
    {
        // Additional constructor code can go here
    }

    void Game::GameLoop(N_Player::Player &player)
    {
        int choice;
        bool keepPlaying = true;
        N_Battle::BattleManager battleManager;
        N_Battle::WildEncounterManager encounterManager;
        N_Pokemon::Pokemon wildPokemon;

        while (keepPlaying)
        {
            // Clear console before showing options
            N_Utility::Utility::ClearConsole();

            // Display options to the player
            cout << "\nWhat would you like to do next, " << player.name << "?\n";
            cout << "1. Battle Wild Pokémon\n";
            cout << "2. Visit PokeCenter\n";
            cout << "3. Challenge Gyms\n";
            cout << "4. Enter Pokémon League\n";
            cout << "5. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            N_Utility::Utility::ClearInputBuffer(); // Clear the input buffer

            // Process the player's choice and display the corresponding message
            switch (choice)
            {
            case 1:
            {
                // Create a scope within case 1
                wildPokemon = encounterManager.GetRandomPokemonFromGrass(forestGrass);
                battleManager.StartBattle(player, wildPokemon);
                break;
            }
            case 2:
            {
                VisitPokeCenter(player);
                break;
            }
            case 3:
            {
                cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
                break;
            }
            case 4:
            {
                cout << "You boldly step towards the Pokémon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
                break;
            }
            case 5:
            {
                cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokémon training!'\n";
                cout << "Are you sure you want to quit? (y/n): ";
                char quitChoice;
                cin >> quitChoice;
                if (quitChoice == 'y' || quitChoice == 'Y')
                {
                    keepPlaying = false;
                }
                break;
            }
            default:
            {
                cout << "That's not a valid choice. Try again!\n";
                break;
            }
            }

            // Wait for Enter key before the screen is cleared and the menu is shown
            // again
            N_Utility::Utility::WaitForEnter();
        }

        cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
    }

    void Game::VisitPokeCenter(N_Player::Player &player)
    {
        if (player.chosenPokemon.GetPokemonCurrentHealth() == player.chosenPokemon.GetPokemonMaxHealth())
        {
            cout << "Your Pokémon is already at full health!\n";
        }
        else
        {
            cout << "You head to the PokeCenter.\n";
            cout << "Healing your Pokémon...\n";
            N_Utility::Utility::WaitForEnter(); // Simulate a short pause for the healing process
            player.chosenPokemon.Heal();        // Heal the player's Pokémon
            cout << player.chosenPokemon.GetPokemonName() << "'s health is fully restored!\n";
        }
    }
}