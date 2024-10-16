#include <vector>

struct Grass;
class Pokemon;

class WildEncounterManager
{
public:
    WildEncounterManager();
    Pokemon GetRandomPokemonFromGrass(const Grass &grass);
};