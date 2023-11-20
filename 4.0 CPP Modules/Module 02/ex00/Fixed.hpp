/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:42:54 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:42:55 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {

  private:
    int _value;
    static const int _bits = 8;

  public:
    Fixed( void );
    Fixed (Fixed const &src);
    Fixed &operator=(Fixed const &rhs);
		~Fixed( void );
    int getRawBits( void ) const;
    void setRawBits( int const raw );

};

#endif
