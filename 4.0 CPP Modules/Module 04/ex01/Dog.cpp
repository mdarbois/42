#include "Dog.hpp"

Dog::Dog(void ) {
    this->_type = "Dog";
    this->_brain = new Brain();
  std::cout << "Dog default  constructor called" << std::endl;
}

Dog::Dog(Dog const & src){
  std::cout << "Dog copy constructor called" << std::endl;
  *this = src;
  return ;
}

Dog &Dog::operator=(Dog const &rhs){
    if (this != &rhs) {
      this->_type = rhs.getType();
      this->_brain = new Brain( *rhs._brain );
    }
  std::cout << "Dog copy assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog(void) {
  delete this->_brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Huffs" << std::endl;
}