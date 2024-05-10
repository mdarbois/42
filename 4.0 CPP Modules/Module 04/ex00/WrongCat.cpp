#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    this->_type = "WrongCat";
  std::cout << "WrongCat default  constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src){
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = src;
  return ;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
    if (this != &rhs) {
		this->_type = rhs.getType();
    }
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  return *this;
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meows" << std::endl;
}