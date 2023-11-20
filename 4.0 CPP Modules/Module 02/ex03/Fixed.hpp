/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:48:44 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:48:45 by mdarbois         ###   ########.fr       */
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
    Fixed (int const i);
    Fixed (float const  f);
    ~Fixed( void );
    Fixed (Fixed const &src);

    Fixed &operator=(Fixed const &rhs);

		bool	operator>(Fixed const &rhs) const;
    bool	operator<(Fixed const &rhs) const;
    bool	operator>=(Fixed const &rhs) const;
    bool	operator<=(Fixed const &rhs) const;
    bool	operator==(Fixed const &rhs) const;
    bool	operator!=(Fixed const &rhs) const;

    Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

    Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

    static Fixed	&min(Fixed &lhs, Fixed &rhs);
    static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed	&max(Fixed &lhs, Fixed &rhs);
    static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);


    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
