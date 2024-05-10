#include "Cat.hpp"

Cat::Cat(void) {
    this->_type = "Cat";
    this->_brain = new Brain();
  std::cout << "Cat default  constructor called" << std::endl;
}

Cat::Cat(Cat const & src){
  std::cout << "Cat copy constructor called" << std::endl;
  *this = src;
  return ;
}

Cat &Cat::operator=(Cat const &rhs){
    if (this != &rhs) {
      this->_type = rhs.getType();
      this->_brain = new Brain( *rhs._brain );
    }
  std::cout << "Cat copy assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat(void) {
  delete this->_brain;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meows" << std::endl;
}