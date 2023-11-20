/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:12:56 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:12:57 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
