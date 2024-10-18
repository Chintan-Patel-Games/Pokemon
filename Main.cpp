#include "../include/Main/Game.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Character/ProfessorOak.hpp"
#include <iostream>

using namespace N_Character;
using namespace N_Player;

int main()
{
    // Continue with the main flow of the game
    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    N_Player::Player* player = new N_Player::Player();

    // Greet the player and offer Pokemon choices
    professor->GreetPlayer();
    professor->OfferPokemonChoices(player);

    // Explain the main quest
    professor->ExplainMainQuest(player);

    // Start the main game loop
    N_Main::Game* game = new N_Main::Game();
    game->GameLoop(player);

    delete(professor);
    delete(player);
    delete(game);
    
    return 0;
}