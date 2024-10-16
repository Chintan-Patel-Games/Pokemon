#pragma once
#include "../include/Battle/BattleState.hpp"
class Player;
class Pokemon;

class BattleManager
{
public:
    void StartBattle(Player &player, Pokemon &wildPokemon);

private:
    BattleState battleState;  // New BattleState object to track the battle
    void Battle();
    void HandleBattleOutcome();
    void UpdateBattleState(); // Method to update the battle state after each turn
};