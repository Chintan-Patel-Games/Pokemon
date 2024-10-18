#pragma once
#include <string>
#include <vector>
#include "Move.hpp"
#include "../include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include "../include/Pokemon/StatusEffects/IStatusEffect.hpp"

namespace N_Pokemon
{
    struct Move;
    enum class StatusEffectsType;
    enum class PokemonType;

    class Pokemon
    {
    public:
        std::string name;
        PokemonType type;
        int health;
        int maxHealth = health;
        int attackPower;
        std::vector<Move> moves; // Store the list of moves
        N_StatusEffects::IStatusEffect* appliedEffect;

        Pokemon();
        Pokemon(std::string p_name, PokemonType p_type, int p_health, std::vector<Move>);
        Pokemon(const Pokemon *other);

        bool IsFainted() const;
        void Heal();
        virtual void Attack(Move selectedMove, Pokemon *target);
        void TakeDamage(int damage);
        void SelectAndUseMove(Pokemon *target);
        void ReduceAttackPower(int reducedDamage);
        bool CanAttack();
        bool CanApplyEffect();
        void ApplyEffect(N_StatusEffects::StatusEffectType effectToApply);
        void ClearEffect();

    protected:
        // Base implementation for selecting and using a move
        void PrintAvailableMoves();
        int SelectMove();
        void UseMove(Move selectedMove, Pokemon *target);
    };
}