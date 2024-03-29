/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:39:57 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:39:57 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string const aName, Weapon const &aWeapon )
				: _name( aName ),	_weapon( aWeapon )
{
	std::cout << this->_name << " is created" << std::endl;
  return ;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " is destroyed" << std::endl;
  return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "." << std::endl;
	return ;
}
