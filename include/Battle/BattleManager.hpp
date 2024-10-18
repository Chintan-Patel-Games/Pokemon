#pragma once
#include "../include/Battle/BattleState.hpp"
#include "../include/Character/Player/Player.hpp"

namespace N_Battle
{
    class Pokemon;

    using namespace N_Character::N_Player;

    class BattleManager
    {
    public:
        void StartBattle(Player &player, N_Pokemon::Pokemon &wildPokemon);

    private:
        BattleState battleState; // New BattleState object to track the battle
        
        void Battle();
        void HandleBattleOutcome();
        void UpdateBattleState(); // Method to update the battle state after each turn
    };
}