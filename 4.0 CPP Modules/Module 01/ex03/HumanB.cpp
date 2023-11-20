/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:12 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:13 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string const aName)
				: _weapon( NULL ), _name( aName )
{
	std::cout << this->_name << " is created" << std::endl;
  return ;
}

HumanB::~HumanB( void )
{
	std::cout << this->_name << " is destroyed" << std::endl;
  return ;
}

void	HumanB::setWeapon( Weapon &aWeapon )
{
  this->_weapon = &aWeapon;
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "." << std::endl;
	return ;
}
