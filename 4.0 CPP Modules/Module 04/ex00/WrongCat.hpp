#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
    WrongCat( void );
    WrongCat (WrongCat const &src);
    WrongCat &operator=(WrongCat const &rhs);
	~WrongCat( void );

    void makeSound() const;
};
#endif