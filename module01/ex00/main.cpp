#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );


int	main(void) {
	Zombie	*oneZombie = newZombie( "Bla" );
	Zombie	*twoZombie = newZombie( "Blo" );
	Zombie	*threeZombie = newZombie( "Blub" );

	randomChump( "Chump" );
	randomChump( "Chomp" );
	randomChump( "Champ" );

	oneZombie->announce();
	delete oneZombie;
	twoZombie->announce();
	threeZombie->announce();
	delete threeZombie;
	delete twoZombie;
	return ( 0 );
}
