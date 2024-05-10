#include "Animal.hpp"

Animal::Animal() : _type("abstractAnimal") {
  std::cout << "Animal default  constructor called" << std::endl;
}

Animal::Animal(Animal const & src){
  std::cout << "Animal copy constructor called" << std::endl;
  *this = src;
  return ;
}

Animal &Animal::operator=(Animal const &rhs){
    if (this != &rhs) {
		this->_type = rhs.getType();
    }
  std::cout << "Animal copy assignment operator called" << std::endl;
  return *this;
}

Animal::~Animal(void) {
  std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

void Animal::makeSound() const {
    std::cout << "Animal sound is triggered" << std::endl;
}

