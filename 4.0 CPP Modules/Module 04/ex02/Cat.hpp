#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        Brain   *_brain;
    public:
        Cat( void );
        Cat (Cat const &src);
        Cat &operator=(Cat const &rhs);
        ~Cat( void );


        void makeSound() const;
};
#endif