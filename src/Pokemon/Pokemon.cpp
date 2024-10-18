#include "../include/Pokemon/Pokemon.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    // Default constructor
    Pokemon::Pokemon() : name("Unknown"), type(PokemonType::Normal), health(50), maxHealth(50), attackPower(10) {}

    // Parameterized constructor
    Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_attackPower) : name(p_name), type(p_type), health(p_health), maxHealth(p_health), attackPower(p_attackPower) {}

    // Copy constructor
    Pokemon::Pokemon(const Pokemon &other) : name(other.name), type(other.type), health(other.health), maxHealth(other.maxHealth), attackPower(other.attackPower) {}

    // Reduce HP by the damage amount
    void Pokemon::TakeDamage(int damage)
    {
        health -= damage; // Reduce HP by the damage amount
        if (IsFainted())
        {
            health = 0; // Ensure HP doesn't go below 0
        }
    }

    // Check if the Pokemon has fainted
    bool Pokemon::IsFainted() const
    {
        return health <= 0; // Return true if HP is 0 or less
    }

    // Restore health to full
    void Pokemon::Heal()
    {
        health = maxHealth; // Restore health to full
    }

    // Attack another Pokemon
    void Pokemon::Attack(Pokemon &target)
    {
        int damage = attackPower; // Use attack power for damage calculation
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        target.TakeDamage(damage);
    }
}