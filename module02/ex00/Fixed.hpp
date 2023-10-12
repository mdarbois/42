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
