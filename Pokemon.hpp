#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
using namespace std;

enum class PokemonType;

class Pokemon
{
public:
    string name;
    PokemonType type;
    int health;
    int maxHealth;

    // Default constructor
    Pokemon();

    // Parameterized constructor
    Pokemon(string p_name, PokemonType p_type, int p_health);

    // Copy constructor
    Pokemon(const Pokemon &other);

    // Destructor
    ~Pokemon();

    void Attack(Pokemon &target);
    void TakeDamage(int damage); // Method to reduce HP
    bool IsFainted() const;  // Method to check if the Pokemon has fainted
};

#endif // POKEMON_HPP