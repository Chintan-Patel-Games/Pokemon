// BattleManager.hpp

#include "BattleState.hpp"
#include "Player.hpp"

class BattleManager
{
public:
    void StartBattle(Player &player, Pokemon &wildPokemon);

private:
    BattleState battleState;  // New BattleState object to track the battle
    void Battle(Pokemon &playerPokemon, Pokemon &wildPokemon);
    void HandleBattleOutcome();
    void UpdateBattleState(); // Method to update the battle state after each turn
};