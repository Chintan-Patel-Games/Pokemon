#pragma once
#include <iostream>
#include "../include/Character/Player/Player.hpp"

class Player;

namespace N_Character
{
    using namespace N_Player;

    class ProfessorOak
    {
    public:
        std::string name;

        ProfessorOak(std::string p_name);
        void GreetPlayer();
        void OfferPokemonChoices(Player* player);
        void ExplainMainQuest(Player* player);
    };
}