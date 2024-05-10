#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <iostream>

class AAnimal {

protected:
    std::string _type;

public:
    AAnimal( void );
    AAnimal (AAnimal const &src);
    AAnimal &operator=(AAnimal const &rhs);
	virtual ~AAnimal( void );

    std::string	getType(void) const;

    virtual void makeSound() const = 0;

};
#endif