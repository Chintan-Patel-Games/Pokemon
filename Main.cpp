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
    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player;

    // Greet the player and offer Pokemon choices
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);

    // Explain the main quest
    professor.ExplainMainQuest(player);

    // Start the main game loop
    Game game;
    game.GameLoop(player);

    return 0;
}