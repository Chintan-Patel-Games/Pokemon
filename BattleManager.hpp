// BattleManager.hpp

#include "Pokemon.hpp"
#include "Player.hpp"

class BattleManager
{
public:
    void StartBattle(Player &player, Pokemon &wildPokemon);

private:
    void Battle(Pokemon &playerPokemon, Pokemon &wildPokemon);
    void HandleBattleOutcome(Pokemon &playerPokemon, bool playerWon);
};