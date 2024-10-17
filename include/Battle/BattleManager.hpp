#pragma once
#include "../include/Character/Player/Player.hpp"
#include "../include/Battle/BattleState.hpp"

namespace N_Battle
{
    class BattleManager
    {
    public:
        void StartBattle(N_Player::Player &player, N_Pokemon::Pokemon &wildPokemon);

    private:
        BattleState battleState; // New BattleState object to track the battle
        void Battle();
        void HandleBattleOutcome();
        void UpdateBattleState(); // Method to update the battle state after each turn
    };
}