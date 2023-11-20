/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:21 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:22 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string const type ) : _type( type )
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const &Weapon::getType( void ) const {
  return ( this->_type );
}

void Weapon::setType( std::string const type ) {
  this->_type = type;
  return ;
}
