#include "../include/Battle/BattleManager.hpp"
#include "../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Pidgey::Pidgey() : Pokemon("Pidgey", PokemonType::Normal, 100, {Move("WING ATTACK", 25), Move("TACKLE", 10)}) {}

        void Pidgey::Attack(Move selectedMove, Pokemon *target)
        {
            Pokemon::Attack(selectedMove, target);

            if (selectedMove.name == "GUST")
            {
                // 20% chance to blow the opponent away
                if (rand() % 100 < 20)
                {
                    std::cout << "... and blew the opponent away!\n";
                    // N_Battle::BattleManager::StopBattle();
                    N_Utility::Utility::WaitForEnter();
                }
            }
        }
    }
}