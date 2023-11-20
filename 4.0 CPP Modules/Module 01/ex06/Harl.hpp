/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:51:08 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:51:09 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>

class Harl {

  public:
    Harl( void );
		~Harl( void );
    void complain( std::string level );

  private:
    void _debug( void );
    void _info( void );
    void _warning( void );
    void _error( void );
};

#endif
