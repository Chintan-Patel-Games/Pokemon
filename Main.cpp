#include <iostream>
#include <limits> // Include this header to use numeric_limits
#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "Utility.hpp"

using namespace std;

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
        name = "Unknown";
        type = PokemonType::Normal;
        health = 50;
    }

    // Parameterized constructor
    Pokemon(string p_name, PokemonType p_type, int p_health)
    {
        name = p_name;
        type = p_type;
        health = p_health;
    }

    // Copy constructor
    Pokemon(const Pokemon &other)
    {
        name = other.name;
        type = other.type;
        health = other.health;
    }

    // Destructor
    ~Pokemon()
    {
        // Destructor message removed
    }

    void attack() { cout << name << " attacks with a powerful move!\n"; }
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
    }

    // Parameterized constructor
    Player(string p_name, Pokemon p_chosenPokemon)
    {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
    }

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
        Utility::WaitForEnter(); // Wait for user to press Enter before proceeding
    }
};

// ProfessorOak class definition
class ProfessorOak
{
public:
    // Attributes
    string name;

    // Parameterized constructor
    ProfessorOak(string p_name) { name = p_name; }

    void GreetPlayer(Player &player)
    {
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        Utility::WaitForEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
        Utility::WaitForEnter();
        cout << name << ": But enough about me. Let's talk about you!\n";
        Utility::WaitForEnter();
    }

    void OfferPokemonChoices(Player &player)
    {
        cout << name << ": First, tell me, what’s your name? \t [Please Enter Your Name]\n";
        cin >> player.name;
        cout << name << ": Ah, " << player.name << "! What a fantastic name!\n";
        Utility::WaitForEnter();
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!\n";
        Utility::WaitForEnter();

        // Presenting Pokemon choices
        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!\n";
        Utility::WaitForEnter();
        cout << name << ": Choose wisely...\n";
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        player.ChoosePokemon(choice);
        Utility::WaitForEnter();
    }

    // New method for the main quest conversation
    void ExplainMainQuest(Player &player)
    {
        // Clear the console
        Utility::ClearConsole();

        cout << "Professor Oak: " << player.name << "!, I am about to explain you about your upcoming grand adventure.\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: You see, becoming a Pokémon Master is no easy feat. It takes courage, wisdom, and a bit of luck!\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: Your mission, should you choose to accept it—and trust me, you really don’t have a choice—is to collect all the Pokémon Badges and conquer the Pokémon League.\n";
        Utility::WaitForEnter();

        cout << "\n" << player.name << ": Wait... that sounds a lot like every other Pokémon game out there...\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: Shhh! Don't break the fourth wall, " << player.name << "! This is serious business!\n";
        Utility::WaitForEnter();

        cout << "\nProfessor Oak: To achieve this, you’ll need to battle wild Pokémon, challenge gym leaders, and of course, keep your Pokémon healthy at the PokeCenter.\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: Along the way, you'll capture new Pokémon to strengthen your team. Just remember—there’s a limit to how many Pokémon you can carry, so choose wisely!\n";
        Utility::WaitForEnter();

        cout << "\n" << player.name << ": Sounds like a walk in the park... right?\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: Hah! That’s what they all say! But beware, young Trainer, the path to victory is fraught with challenges. And if you lose a battle... well, let’s just say you'll be starting from square one.\n";
        Utility::WaitForEnter();

        cout << "\nProfessor Oak: So, what do you say? Are you ready to become the next Pokémon Champion?\n";
        Utility::WaitForEnter();
        cout << "\n" << player.name << ": Ready as I’ll ever be, Professor!\n";
        Utility::WaitForEnter();

        cout << "\nProfessor Oak: That’s the spirit! Now, your journey begins...\n";
        Utility::WaitForEnter();
        cout << "Professor Oak: But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
        Utility::WaitForEnter();
    }
};

// Function to handle the main game loop
void GameLoop(Player &player)
{
    int choice;
    bool keepPlaying = true;

    while (keepPlaying)
    {
        // Clear console before showing options
        Utility::ClearConsole();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokémon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the newline character left in the buffer after cin >> choice
        Utility::ClearInputBuffer();

        // Process the player's choice and display the corresponding message
        switch (choice)
        {
        case 1:
            cout << "You look around... but all the wild Pokémon are on vacation. Maybe try again later?\n";
            break;
        case 2:
            cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokémon will have to tough it out for now!\n";
            break;
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
            break;
        case 4:
            cout << "You boldly step towards the Pokémon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
            break;
        case 5:
            cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokémon training!'\n";
            cout << "Are you sure you want to quit? (y/n): ";

            char quitChoice;
            cin >> quitChoice;

            if (quitChoice == 'y' || quitChoice == 'Y')
            {
                keepPlaying = false;
            }
            break;
        default:
            cout << "That's not a valid choice. Try again!\n";
            break;
        }

        // Wait for Enter key before the screen is cleared and the menu is shown
        // again
        Utility::WaitForEnter();
    }

    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
}

int main()
{
    // Create Pokemon and Player objects for the game
    Pokemon charmander("Charmander", PokemonType::Fire, 100); // Using parameterized constructor

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    // Greet the player and offer Pokemon choices
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);

    // Explain the main quest
    professor.ExplainMainQuest(player);

    // Start the main game loop
    GameLoop(player);
}