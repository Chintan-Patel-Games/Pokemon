#pragma once
#include "../include/Battle/BattleState.hpp"
#include "../include/Character/Player/Player.hpp"

namespace N_Battle
{
    class Pokemon;

    using namespace N_Character::N_Player;
    using namespace N_Pokemon;

    class BattleManager
    {
    public:
        void StartBattle(N_Character::N_Player::Player* player, N_Pokemon::Pokemon* wildPokemon);
        void StopBattle();

    private:
        BattleState battleState; // New BattleState object to track the battle
        
        void Battle();
        void HandleBattleOutcome();
        void UpdateBattleState(); // Method to update the battle state after each turn
    };
}