#include "Game.hpp"
#include "Player.hpp"
#include "PokemonChoice.hpp"
#include "PokemonType.hpp"
#include "ProfessorOak.hpp"
#include "Utility.hpp"
#include <iostream>
#include <limits> // Include this header to use std::numeric_limits
#include <string>

using namespace std;

int main()
{
    // Create Pokemon and Player objects for the game
    Pokemon charmander("Charmander", PokemonType::Fire, 100); // Using parameterized constructor

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    // Greet the player and offer Pokemon choices
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);

    // Explain the main quest
    professor.ExplainMainQuest(player);

    Game game;
    
    // Start the main game loop
    game.GameLoop(player);
}