/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:13:02 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:13:03 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie {

  public:

    void announce( void );
    Zombie( void );
    Zombie( std::string name );
    ~Zombie( void );
    std::string getName( void ) const;
    void setName( std::string const name );

  private:

    std::string _name;
};

#endif
