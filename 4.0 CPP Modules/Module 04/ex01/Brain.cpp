#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain default  constructor called" << std::endl;
}

Brain::Brain(Brain const & src){
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
  return ;
}

Brain &Brain::operator=(Brain const &rhs){
    if (this != &rhs) {
		for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = rhs._ideas[i];
        }
    }
  std::cout << "Brain copy assignment operator called" << std::endl;
  return *this;
}

Brain::~Brain(void) {
  std::cout << "Brain destructor called" << std::endl;
}


