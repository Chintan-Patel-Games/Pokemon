#include "Game.hpp"
#include "Player.hpp"
#include "PokemonType.hpp"
#include "Utility.hpp"
#include "WildEncounterManager.hpp"
#include <iostream>
using namespace std;

Game::Game()
{
    // Create a sample grass environment with actual Pokemon objects
    forestGrass = {"Forest",
                   {Pokemon("Pidgey", PokemonType::Normal, 40),
                    Pokemon("Caterpie", PokemonType::Bug, 35),
                    Pokemon("Zubat", PokemonType::Poison, 30)},
                   70};
}

void Game::GameLoop(Player &player)
{
    int choice;
    bool keepPlaying = true;

    while (keepPlaying)
    {
        // Clear console before showing options
        Utility::ClearConsole();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokémon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Utility::ClearInputBuffer(); // Clear the input buffer

        // Process the player's choice and display the corresponding message
        switch (choice)
        {
        case 1:
        {
            WildEncounterManager encounterManager;
            Pokemon encounteredPokemon = encounterManager.getRandomPokemonFromGrass(forestGrass);
            cout << "A wild " << encounteredPokemon.name << " appeared!\n";
            break;
        }
        case 2:
        {
            cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokémon will have to tough it out for now!\n";
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

        // Flush output to ensure it appears immediately
        cout << flush;

        // Wait for Enter key before the screen is cleared and the menu is shown
        // again
        Utility::WaitForEnter();
    }

    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
}