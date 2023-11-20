/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:48:39 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:48:40 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _value(0) {

}

Fixed::Fixed(Fixed const & src){

  *this = src;
  return ;
}

Fixed &Fixed::operator=(Fixed const &rhs){

  if (this != &rhs)
    this->_value = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed(void) {

}

Fixed::Fixed(int const i): _value(i << _bits)
{

}

Fixed::Fixed(float const f): _value( roundf(f * (1 << _bits)))
{

}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}


int Fixed::getRawBits( void ) const{
  return this->_value;
}

void Fixed::setRawBits( int const raw ) {
  this->_value = raw;
  return;
}

bool	Fixed::operator>( Fixed const &rhs ) const
{
	return (this->_value > rhs.getRawBits());
}
bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs.getRawBits());
}
bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}
bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}
bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs.getRawBits());
}
bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs.getRawBits());
}


Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return( Fixed	(this->toFloat() + rhs.toFloat()));
}
Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return ( Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return( Fixed	(this->toFloat() * rhs.toFloat()));
}
Fixed	Fixed::operator/(Fixed const &copy) const
{
	return(Fixed (this->toFloat() / copy.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	tmp( *this );
	++(*this);
	return (tmp);
}
Fixed	&Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp( *this );
	--(*this);
	return (tmp);
}

Fixed &	Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed &	Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if ( lhs >= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}
