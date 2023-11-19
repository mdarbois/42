#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout <<  "FragTrap default constructor called."  << std::endl;
	this-> _hit = 100;
	this->_energy = 100;
	this->_damage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout <<  "A FragTrap named \"" << name << "\" was constructed." << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout <<  "The FragTrap named \"" << this->_name << "\" was destroyed." << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap const & src) {
	std::cout << "Frag Trap copy assignment operator called" << std::endl;
  if (this != &src) {
		this->_name = src.getName();
		this->_hit = src.getHit();
		this->_energy = src.getEnergy();
		this->_damage = src.getDamage();
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap named \"" << this->_name << "\" gives you a high five" << std::endl;
}
