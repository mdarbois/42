#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("abstractWrongAnimal") {
  std::cout << "WrongAnimal default  constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = src;
  return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs){
    if (this != &rhs) {
		this->_type = rhs.getType();
    }
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound is triggered" << std::endl;
}