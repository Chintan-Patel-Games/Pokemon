#include <iostream>

using namespace std;

// Define an enum for Pokemon choices
enum class PokemonChoice
{
    Charmander = 1,
    Bulbasaur,
    Squirtle,
    Pikachu // Default choice
};

// Define an enum for Pokemon types
enum class PokemonType
{
    Fire,
    Grass,
    Water,
    Electric,
    Normal // Added for the default constructor
};

// Pokemon class definition
class Pokemon
{
public:
    // Attributes
    string name;
    PokemonType type;
    int health;

    // Default constructor
    Pokemon()
    {
        name = "Pikachu";
        type = PokemonType::Electric;
        health = 10;
        cout << "A new Pokemon has been created with the default constructor!\n";
    }

    // Parameterized constructor
    Pokemon(string p_name, PokemonType p_type, int p_health)
    {
        name = p_name;
        type = p_type;
        health = p_health;
        cout << "A new Pokemon named " << name << " has been created!\n";
    }

    // Copy constructor
    Pokemon(const Pokemon &other)
    {
        name = other.name;
        type = other.type;
        health = other.health;
        cout << "A new Pokemon has been copied from " << other.name << "!\n";
    }

    // Destructor
    ~Pokemon()
    {
        cout << name << " has been released.\n";
    }

    // Method to simulate attacking (just for demonstration)
    void attack()
    {
        cout << name << " attacks with a powerful move!\n";
    }
};

// Player class definition
class Player
{
public:
    // Attributes
    string name;
    Pokemon chosenPokemon;

    // Default constructor
    Player()
    {
        name = "Trainer";
        chosenPokemon = Pokemon(); // Using the default Pokemon constructor
        cout << "A new player named " << name << " has been created!\n";
    }

    // Parameterized constructor
    Player(string p_name, Pokemon p_chosenPokemon)
    {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
        cout << "Player " << name << " has been created!\n";
    }

    // Copy constructor
    Player(const Player &other)
    {
        name = other.name;
        chosenPokemon = other.chosenPokemon;
        cout << "A new player has been copied from " << other.name << "!\n";
    }

    // Method to choose a Pokemon
    void ChoosePokemon(int choice)
    {
        switch ((PokemonChoice)choice)
        {
        case PokemonChoice::Charmander:
            chosenPokemon = Pokemon("Charmander", PokemonType::Fire, 100);
            break;
        case PokemonChoice::Bulbasaur:
            chosenPokemon = Pokemon("Bulbasaur", PokemonType::Grass, 100);
            break;
        case PokemonChoice::Squirtle:
            chosenPokemon = Pokemon("Squirtle", PokemonType::Water, 100);
            break;
        default:
            chosenPokemon = Pokemon("Pikachu", PokemonType::Electric, 100);
            break;
        }
        cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
    }
};

// ProfessorOak class definition
class ProfessorOak
{
public:
    // Attributes
    string name;

    // Parameterized constructor
    ProfessorOak(string p_name)
    {
        name = p_name;
    }

    // Method to greet the player
    void GreetPlayer(Player &player)
    {
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
        cout << name << ": But enough about me. Let's talk about you!\n";
    }

    // Method to ask the player to choose a Pokemon
    void OfferPokemonChoices(Player &player)
    {
        cout << name << ": First, tell me, what’s your name?\n";
        cin >> player.name;
        cout << name << ": Ah, " << player.name << "! What a fantastic name!\n";
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!\n";

        // Presenting Pokemon choices
        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!\n";
        cout << name << ": Choose wisely...\n";
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        player.ChoosePokemon(choice);
    }
};

int main()
{
    // Task 1: Test default and parameterized constructors
    Pokemon defaultPokemon;                                   // Using default constructor
    Pokemon charmander("Charmander", PokemonType::Fire, 100); // Using parameterized constructor

    cout << "Pokemon Details:\n";
    cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << "\n";
    cout << "Name: " << charmander.name << "\nType: " << (int)charmander.type << "\nHealth: " << charmander.health << "\n";

    // Task 2: Test the copy constructor
    Pokemon bulbasaur("Bulbasaur", PokemonType::Grass, 100); // Create a Pokemon
    Pokemon bulbasaurCopy = bulbasaur;                       // Copy the Pokemon
    cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << "\n";

    // Modify the copy
    bulbasaurCopy.health = 80;
    cout << "After Modification:\n";
    cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << "\n";

    // Task 3: Test the destructor
    {
        Pokemon squirtle("Squirtle", PokemonType::Water, 100); // Pokemon will be destroyed at the end of this scope
    } // Destructor will be called here

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);
    Player playerCopy = player;

    // Greet the player and offer Pokemon choices
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);

    // Conclude the first chapter
    cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";
}