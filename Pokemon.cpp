#include "Pokemon.hpp"
#include "PokemonType.hpp"
#include <iostream>
using namespace std;

// Default constructor
Pokemon::Pokemon() : name("Unknown"), type(PokemonType::Normal), health(50) {}

// Parameterized constructor
Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health) : name(p_name), type(p_type), health(p_health) {}

// Copy constructor
Pokemon::Pokemon(const Pokemon &other) : name(other.name), type(other.type), health(other.health) {}

// Destructor
Pokemon::~Pokemon()
{
    // Destructor logic (if any) goes here
}

void Pokemon::Attack(Pokemon &target)
{
    int damage = 10; // Fixed damage for simplicity
    cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
    target.TakeDamage(damage); // Apply damage to the target Pokémon
}

void Pokemon::TakeDamage(int damage)
{
    health -= damage; // Reduce HP by the damage amount
    if (health < 0)
    {
        health = 0; // Ensure HP doesn't go below 0
    }
}

bool Pokemon::IsFainted() const
{
    return health <= 0; // Return true if HP is 0 or less
}