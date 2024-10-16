#include "Pokemon.hpp"
#include "PokemonType.hpp"
#include <iostream>
using namespace std;

// Default constructor
Pokemon::Pokemon() : name("Unknown"), type(PokemonType::Normal), health(50) {}

// Parameterized constructor
Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_attackPower) : name(p_name), type(p_type), health(p_health), attackPower(p_attackPower) {}

// Copy constructor
Pokemon::Pokemon(const Pokemon &other) : name(other.name), type(other.type), health(other.health), attackPower(other.attackPower) {}

// Destructor
Pokemon::~Pokemon()
{
    // Destructor logic (if any) goes here
}

void Pokemon::Attack(Pokemon &target)
{
    int damage = attackPower; // Use attack power for damage calculation
    std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
    target.TakeDamage(damage);
}

void Pokemon::TakeDamage(int damage)
{
    health -= damage; // Reduce HP by the damage amount
    if (Pokemon::IsFainted())
    {
        health = 0; // Ensure HP doesn't go below 0
    }
}

bool Pokemon::IsFainted() const
{
    return health <= 0; // Return true if HP is 0 or less
}

void Pokemon::Heal()
{
    health = maxHealth; // Restore health to full
}

void Pokemon::PokemonStats(Pokemon &playerPokemon)
{
    cout << "Here are the stats of your Pokemon" << endl;
    cout << "Name          : " << playerPokemon.name << endl;
    cout << "CurrentHealth : " << playerPokemon.health << endl;
    cout << "MaxHealth     : " << playerPokemon.maxHealth << endl;
    cout << "Attack Power  : " << playerPokemon.attackPower << endl;
}