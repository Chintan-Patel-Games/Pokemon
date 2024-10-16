#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonChoice.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Utility/Utility.hpp"
#include "iostream"
using namespace std;

Player::Player()
{
    name = "Trainer";
    chosenPokemon = Pokemon(); // Using the default Pokemon constructor
}

Player::Player(string p_name, Pokemon p_chosenPokemon)
{
    name = p_name;
    chosenPokemon = p_chosenPokemon;
}

void Player::ChoosePokemon(int choice)
{
    switch ((PokemonChoice)choice)
    {
    case PokemonChoice::Charmander:
        chosenPokemon = Pokemon("Charmander", PokemonType::Fire, 100, 20);
        break;
    case PokemonChoice::Bulbasaur:
        chosenPokemon = Pokemon("Bulbasaur", PokemonType::Grass, 100, 20);
        break;
    case PokemonChoice::Squirtle:
        chosenPokemon = Pokemon("Squirtle", PokemonType::Water, 100, 20);
        break;
    default:
        chosenPokemon = Pokemon("Pikachu", PokemonType::Electric, 100, 20);
        break;
    }
    cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
    Utility::WaitForEnter(); // Wait for user to press Enter before proceeding
}