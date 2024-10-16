#include <iostream>
using namespace std;

class Player;

class ProfessorOak
{
public:
    string name;

    ProfessorOak(string p_name);
    void GreetPlayer(Player &player);
    void OfferPokemonChoices(Player &player);
    void ExplainMainQuest(Player &player);
};