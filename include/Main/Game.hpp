#pragma once
#include "../include/Battle/BattleManager.hpp"
#include "../include/Battle/WildEncounterManager.hpp"
#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/Grass.hpp"

namespace N_Main
{
    using namespace N_Pokemon;
    using namespace N_Character::N_Player;
    
    class Game
    {
    private:
        Grass* forestGrass = nullptr;
        N_Battle::BattleManager* battleManager = nullptr; // Pointer to BattleManager
        N_Battle::WildEncounterManager* encounterManager = nullptr; // Pointer to WildEncounterManager
        N_Pokemon::Pokemon* wildPokemon = nullptr; // Pointer for Pokemon

    public:
        Game();
        ~Game();
        void GameLoop(Player* &player);
        void VisitPokeCenter(Player* &player);
    };
}