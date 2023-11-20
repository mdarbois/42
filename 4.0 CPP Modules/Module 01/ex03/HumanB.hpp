/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:08 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:09 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B_HPP__
#define __HUMAN_B_HPP__

#include "Weapon.hpp"

class HumanB {

  public:
      HumanB( std::string const aName );
      ~HumanB( void );
      void attack( void );
      void	setWeapon(Weapon &aWeapon);

  private:
    Weapon *_weapon;
    std::string const _name;

};

#endif
