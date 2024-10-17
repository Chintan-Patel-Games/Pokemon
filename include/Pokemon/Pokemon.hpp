#pragma once
#include <string>

namespace N_Pokemon
{
    enum class PokemonType;
    
    class Pokemon
    {
    protected:
        std::string name;
        PokemonType type;
        int health;
        int maxHealth = health;
        int attackPower;

    public:
        Pokemon();
        Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_attackPower);
        Pokemon(const Pokemon &other);

        std::string GetPokemonName() { return name; }
        int GetPokemonCurrentHealth() { return health; }
        int GetPokemonMaxHealth() { return maxHealth; }
        bool IsFainted() const;
        void Heal();
        void Attack(Pokemon &target);
        void TakeDamage(int damage);
    };
}