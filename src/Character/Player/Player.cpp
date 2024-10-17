#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonChoice.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include "iostream"

namespace N_Player
{
    Player::Player()
    {
        name = "Trainer";
        chosenPokemon = N_Pokemon::Pokemon(); // Using the default Pokemon constructor
    }

    Player::Player(std::string p_name, N_Pokemon::Pokemon p_chosenPokemon)
    {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
    }

    void Player::ChoosePokemon(int choice)
    {
        switch ((N_Pokemon::PokemonChoice)choice)
        {
        case N_Pokemon::PokemonChoice::Charmander:
            chosenPokemon = N_Pokemon::Pokemon("Charmander", N_Pokemon::PokemonType::Fire, 100, 20);
            break;
        case N_Pokemon::PokemonChoice::Bulbasaur:
            chosenPokemon = N_Pokemon::Pokemon("Bulbasaur", N_Pokemon::PokemonType::Grass, 100, 20);
            break;
        case N_Pokemon::PokemonChoice::Squirtle:
            chosenPokemon = N_Pokemon::Pokemon("Squirtle", N_Pokemon::PokemonType::Water, 100, 20);
            break;
        default:
            chosenPokemon = N_Pokemon::Pokemon("Pikachu", N_Pokemon::PokemonType::Electric, 100, 20);
            break;
        }
        std::cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
        N_Utility::Utility::WaitForEnter(); // Wait for user to press Enter before proceeding
    }
}