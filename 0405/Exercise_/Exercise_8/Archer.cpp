#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
}

