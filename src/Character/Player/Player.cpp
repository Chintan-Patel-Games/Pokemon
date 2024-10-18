#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonChoice.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../include/Pokemon/Pokemons/Charmander.hpp"
#include "../include/Pokemon/Pokemons/Balbasaur.hpp"
#include "../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../include/Utility/Utility.hpp"
#include "iostream"

namespace N_Character
{
    namespace N_Player
    {
        using namespace N_Utility;
        using namespace N_Pokemon;
        using namespace N_Pokemons;

        Player::Player()
        {
            name = "Trainer";
        }

        Player::Player(std::string p_name)
        {
            name = p_name;
        }

        void Player::ChoosePokemon(int choice)
        {
            switch ((PokemonChoice)choice)
            {
            case PokemonChoice::Charmander:
                chosenPokemon = new Charmander();
                break;
            case PokemonChoice::Bulbasaur:
                chosenPokemon = new Balbasaur();
                break;
            case PokemonChoice::Squirtle:
                chosenPokemon = new Squirtle();
                break;
            default:
                chosenPokemon = new Pikachu();
                break;
            }
            std::cout << "Player " << name << " chose " << chosenPokemon->name << "!\n";
            Utility::WaitForEnter(); // Wait for user to press Enter before proceeding
        }
    }
}