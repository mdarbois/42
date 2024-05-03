#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

  private:
        Brain   *_brain;
    public:
        Dog( void );
        Dog (Dog const &src);
        Dog &operator=(Dog const &rhs);
        virtual ~Dog( void );
        
        void makeSound() const;
};
#endif