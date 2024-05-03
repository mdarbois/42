#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

public:
    Dog( void );
    Dog (Dog const &src);
    Dog &operator=(Dog const &rhs);
	virtual ~Dog( void );
    
    void makeSound() const;
};
#endif