#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

public:
    Cat( void );
    Cat (Cat const &src);
    Cat &operator=(Cat const &rhs);
	~Cat( void );


    void makeSound() const;
};
#endif