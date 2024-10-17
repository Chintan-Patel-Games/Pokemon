#include "../include/Main/Game.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonChoice.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Character/ProfessorOak.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>
#include <limits> // Include this header to use std::numeric_limits
#include <string>

using namespace std;

int main()
{
    // Continue with the main flow of the game
    N_Character::ProfessorOak professor("Professor Oak");
    N_Player::Player player;

    // Greet the player and offer Pokemon choices
    professor.GreetPlayer();
    professor.OfferPokemonChoices(player);

    // Explain the main quest
    professor.ExplainMainQuest(player);

    // Start the main game loop
    N_Main::Game game;
    game.GameLoop(player);

    return 0;
}