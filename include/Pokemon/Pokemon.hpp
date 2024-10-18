#pragma once
#include <string>
#include <vector>
#include "../include/Pokemon/Move.hpp"

namespace N_Pokemon
{
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

        Pokemon();
        Pokemon(std::string p_name, PokemonType p_type, int p_health, std::vector<Move> p_moves);
        Pokemon(const Pokemon *other);

        bool IsFainted() const;
        void Heal();
        virtual void Attack(Move selectedMove, Pokemon *target) = 0;
        void TakeDamage(int damage);
        void ReduceAttackPower(int reducedDamage, Pokemon *target);

    // protected:
        // Base implementation for selecting and using a move
        void SelectAndUseMove(Pokemon *target);
        void PrintAvailableMoves();
        int SelectMove();
        void UseMove(Move selectedMove, Pokemon *target);
    };
}