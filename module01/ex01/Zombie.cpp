#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A zombie appeared!" << std::endl;
	return ;
}

Zombie::Zombie( std::string name ) : _name( name ) {

  std::cout << this->getName() << ":" << " was created" << std::endl;
}

Zombie::~Zombie( void ) {
  std::cout << this->getName() << " was destructed" << std::endl;
}

std::string Zombie::getName( void ) const{
  return ( this->_name );
}

void Zombie::setName( std::string const name ) {
  this->_name = name;
  return ;
}


void Zombie::announce() {
  std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
