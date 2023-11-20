/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:02 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:03 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A_HPP__
#define __HUMAN_A_HPP__

#include "Weapon.hpp"

class HumanA
{
  public:
      HumanA( std::string const aName, Weapon const &aWeapon );
      ~HumanA( void );
      void attack ( void );

  private:
      std::string const _name;
      Weapon const &_weapon;
};
#endif
