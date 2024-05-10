#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {

protected:
    std::string _type;

public:
    Animal( void );
    Animal (Animal const &src);
    Animal &operator=(Animal const &rhs);
	virtual ~Animal( void );

    std::string	getType(void) const;

    virtual void makeSound() const;

};
#endif