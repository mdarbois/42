#include "Fixed.hpp"
#include <cmath>

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

Fixed::Fixed(int const i): _value(i << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f): _value( roundf(f * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
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
