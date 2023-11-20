/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:26 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:28 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon {

  public:
    Weapon( std::string const type );
		~Weapon( void );
		std::string const	&getType( void ) const;
		void				setType( std::string const type );

  private:
    std::string _type;
};

#endif
