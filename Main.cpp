#include <iostream>

using namespace std;

int main()
{
    cout << "Professor Oak : Welcome to the world of Pokémon! I am Professor Oak.\n\n";

    cout << "Enter your name : ";
    string player_name;
    cin >> player_name;

    cout << "\nProfesor Oak : Greetings " << player_name << ". So you wish to become the World's Best Pokemon Trainer, but the road you want to choose will not be an easy one. \n\nProfesor Oak : You'll have to face various Pokemons to capture them and train them to their perfection, and remember to make them comfortable with you as well" << endl;

    cout << "\nProfesor Oak : Great start, Trainer! Looks like you’ve mastered the opening of every trainer adventure. Keep this up, and you’ll be a pokemon master in no time!"
         << endl;

    cout << "\nProfesor Oak : You can choose one of the following Pokémon:\n"
         << endl;

    cout << "1. Bulbasaur\n2. Charmander\n3. Squirtle"
         << endl;

    cout << "\nProfesor Oak : Today is a momentous day — you’ll be choosing your very first Pokémon." << endl;

    cout << "\nProfesor Oak : Every great Trainer remembers this moment for the rest of their lives." << endl;

    cout << "\nProfesor Oak : So, choose wisely, young one!\n" << endl;

    int choice;
    cout << player_name << " : Your choice :- ";
    cin >> choice;

    if (choice == 1)
        cout << "\nProfesor Oak : You chose Bulbasaur! A wise choice." << endl;

    else if (choice == 2)
        cout << "\nProfesor Oak : You chose Charmander! A fiery choice." << endl;

    else if (choice == 3)
        cout << "\nProfesor Oak : You chose Squirtle! A cool choice." << endl;

    else
        cout << "\nProfesor Oak : Invalid choice. Please restart the game." << endl;

    cout << "\nProfesor Oak : Ah, an excellent choice!" << endl;

    cout << "\nProfesor Oak : But beware, Trainer, this is only the beginning." << endl;

    cout << "\nProfesor Oak : Your journey is about to unfold." << endl;

    cout << "\nProfesor Oak : Now let’s see if you’ve got what it takes to keep going!" << endl;

    cout << "\nProfesor Oak : Good luck, and remember… Choose wisely!" << endl;
}