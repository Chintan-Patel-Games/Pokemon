#include "../include/Character/Player/Player.hpp"
#include "../include/Pokemon/PokemonChoice.hpp"
#include "../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
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
            chosenPokemon = new Pokemon(); // Using the default Pokemon constructor
        }

        Player::Player(std::string p_name, Pokemon* p_chosenPokemon)
        {
            name = p_name;
            chosenPokemon = p_chosenPokemon;
        }

        Player::~Player()
        {
            delete chosenPokemon;
        }

        void Player::ChoosePokemon(int choice)
        {
            switch ((PokemonChoice)choice)
            {
            case PokemonChoice::Charmander:
                chosenPokemon = new Pokemon("Charmander", PokemonType::Fire, 100, 20);
                break;
            case PokemonChoice::Bulbasaur:
                chosenPokemon = new Pokemon("Bulbasaur", PokemonType::Grass, 100, 20);
                break;
            case PokemonChoice::Squirtle:
                chosenPokemon = new Pokemon("Squirtle", PokemonType::Water, 100, 20);
                break;
            default:
                chosenPokemon = new Pokemon("Pikachu", PokemonType::Electric, 100, 20);
                break;
            }
            std::cout << "Player " << name << " chose " << chosenPokemon->GetPokemonName() << "!\n";
            Utility::WaitForEnter(); // Wait for user to press Enter before proceeding
        }
    }
}