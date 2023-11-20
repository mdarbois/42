/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:08 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:45:09 by mdarbois         ###   ########.fr       */
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
    ~Fixed( void );
    Fixed (Fixed const &src);
    Fixed &operator=(Fixed const &rhs);

    Fixed (int const i);
    Fixed (float const  f);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
