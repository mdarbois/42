#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
  Zombie *aZombie = new Zombie( name );

  aZombie->announce();
  return ( aZombie );
}
