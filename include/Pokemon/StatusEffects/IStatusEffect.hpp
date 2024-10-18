#pragma once
#include "../include/Pokemon/Pokemon.hpp"
#include <iostream>
#include <string>

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        // Default constructor
        class IStatusEffect
        {
        public:
            // Apply the effect (e.g., poison, burn)
            virtual void ApplyEffect(Pokemon *target) = 0;

            // Get the name of the effect
            virtual std::string GetEffectName() = 0;

            // Apply the changes due to effect after the end of each turn
            // Returns true if the Pokémon can move, else false
            virtual bool TurnEndEffect(Pokemon *target) = 0;

            // Remove the effect
            virtual void ClearEffect(Pokemon *target) = 0;

            virtual ~IStatusEffect() = default;
        };
    }
}