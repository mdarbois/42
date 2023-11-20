/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:42:46 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:42:47 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {
  std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(Fixed const & src){
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return ;
}


Fixed &Fixed::operator=(Fixed const &rhs){
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->_value = rhs.getRawBits();
  return *this;
}


Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}

void Fixed::setRawBits( int const raw ) {
  this->_value = raw;
  return;
}
