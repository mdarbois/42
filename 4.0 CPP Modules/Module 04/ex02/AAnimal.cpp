#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("abstractAAnimal") {
  std::cout << "AAnimal default  constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src){
  std::cout << "AAnimal copy constructor called" << std::endl;
  *this = src;
  return ;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs){
    if (this != &rhs) {
		this->_type = rhs.getType();
    }
  std::cout << "AAnimal copy assignment operator called" << std::endl;
  return *this;
}

AAnimal::~AAnimal(void) {
  std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->_type);
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal sound is triggered" << std::endl;
}

