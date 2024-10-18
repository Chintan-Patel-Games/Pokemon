#include "../include/Pokemon/StatusEffects/BurnEffect.hpp"
#include "../include/Pokemon/Pokemon.hpp"
// #include "../include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void BurnEffect::ApplyEffect(Pokemon *target)
        {
            std::cout << target->name << " is buring! It may not be able to move!\n";

            // Effect lasts between 1 and 3 turns randomly
            turnsLeft = rand() % 3 + 1;
        }

        std::string BurnEffect::GetEffectName()
        {
            return "Burn";
        }

        // Determines whether the Pokémon can act at the end of the turn
        // Returns false if the paralysis prevents the Pokémon from moving
        bool BurnEffect::TurnEndEffect(Pokemon *target)
        {
            if (turnsLeft <= 0)
            {
                ClearEffect(target);
                return true; // Can move as the effect is cleared
            }
            turnsLeft--;

            // Generates a number between 0 and 3
            int paralysis_chance = rand() % 4;

            // 25% chance that the Pokémon cannot move due to paralysis
            if (paralysis_chance == 0)
            {
                std::cout << target->name << " is buring! It can't move!\n";
                return false; // Pokémon cannot act this turn
            }

            // Otherwise, it can act normally
            std::cout << target->name << " shakes off the buring momentarily and can move!\n";
            return true; // Pokémon can act this turn
        }

        void BurnEffect::ClearEffect(Pokemon *target)
        {
            std::cout << target->name << " is no longer buring!\n";
            target->ClearEffect();
        }
    }
}