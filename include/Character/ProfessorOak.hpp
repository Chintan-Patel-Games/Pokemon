#pragma once
#pragma once
#include "../include/Character/Player/Player.hpp"
#include <iostream>

namespace N_Character
{
    class ProfessorOak
    {
    public:
        std::string name;

        ProfessorOak(std::string p_name);
        void GreetPlayer();
        void OfferPokemonChoices(N_Player::Player &player);
        void ExplainMainQuest(N_Player::Player &player);
    };
}