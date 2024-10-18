#pragma once
#include "../include/Pokemon/StatusEffects/IStatusEffect.hpp"

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        class PoisonEffect : public IStatusEffect
        {
        private:
            int turnsLeft; // Track the remaining turns for the effect
        public:
            void ApplyEffect(Pokemon* target) override;
            std::string GetEffectName() override;
            bool TurnEndEffect(Pokemon* target) override;
            void ClearEffect(Pokemon* target) override;
        };
    }
}
