#include "../include/Pokemon/Pokemon.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Move.hpp"
#include "../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
    // Default constructor
    Pokemon::Pokemon() : name("Unknown"), type(PokemonType::Normal), health(50), maxHealth(50), attackPower(10) {}

    // Parameterized constructor
    Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, std::vector<Move> p_moves) : name(p_name), type(p_type), health(p_health), maxHealth(p_health), moves(p_moves) {}

    // Copy constructor
    Pokemon::Pokemon(const Pokemon *other) : name(other->name), type(other->type), health(other->health), maxHealth(other->maxHealth), attackPower(other->attackPower) {}

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

    void Pokemon::Attack(Move selectedMove, Pokemon *target) { target->TakeDamage(selectedMove.power); }

    void Pokemon::ReduceAttackPower(int reducedDamage, Pokemon *target) { target->attackPower = 5; };

    void Pokemon::SelectAndUseMove(Pokemon *target)
    {
        PrintAvailableMoves();

        int choice = SelectMove();
        Move selectedMove = moves[choice - 1];

        UseMove(selectedMove, target);
    }

    void Pokemon::PrintAvailableMoves()
    {
        std::cout << name << "'s available moves:\n";

        // List out all moves for the player to choose from
        for (size_t i = 0; i < moves.size(); ++i)
        {
            std::cout << i + 1 << ": " << moves[i].name << " (Power: " << moves[i].power << ")\n";
        }
    }

    int Pokemon::SelectMove()
    {
        // Ask the player to select a move
        int choice;
        std::cout << "Choose a move: ";
        std::cin >> choice;

        // Validate the choice
        while (choice < 1 || choice > static_cast<int>(moves.size()))
        {
            std::cout << "Invalid choice. Try again: ";
            std::cin >> choice;
        }

        return choice;
    }

    void Pokemon::UseMove(Move selectedMove, Pokemon *target)
    {
        std::cout << name << " used " << selectedMove.name << "!\n";

        Attack(selectedMove, target);

        N_Utility::Utility::WaitForEnter();

        std::cout << "...\n";
        N_Utility::Utility::WaitForEnter();

        if (target->IsFainted())
            std::cout << target->name << " fainted!\n";
        else
            std::cout << target->name << " has " << target->health << " HP left.\n";
    }
}