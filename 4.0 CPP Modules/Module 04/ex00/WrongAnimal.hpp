#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal {

protected:
    std::string _type;

public:
    WrongAnimal( void );
    WrongAnimal (WrongAnimal const &src);
    WrongAnimal &operator=(WrongAnimal const &rhs);
	~WrongAnimal( void );

    std::string	getType(void) const;

    void makeSound() const;

};
#endif