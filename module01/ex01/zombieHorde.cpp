#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {

  if ( N <= 0 )
		return ( NULL );
  Zombie *aZombieHorde = new Zombie[N];
  for (int i = 0; i < N; i++) {
		aZombieHorde[i].setName( name );
	}
	return ( aZombieHorde );
}
