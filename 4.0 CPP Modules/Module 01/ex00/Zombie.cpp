/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:10:21 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:10:22 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name( name ) {

  std::cout << this->getName() << ":" << "was created" << std::endl;
}

Zombie::~Zombie( void ) {
  std::cout << this->getName() << "was destructed" << std::endl;
}

std::string Zombie::getName( void ) {
  return ( this->_name );
}

void Zombie::announce() {
  std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
