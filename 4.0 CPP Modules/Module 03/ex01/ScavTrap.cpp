#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout <<  "ScavTrap default constructor called."  << std::endl;
	this-> _hit = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_guard = false;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout <<  "A ScavTrap named \"" << name << "\" was constructed." << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_guard = false;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout <<  "The ScavTrap named \"" << this->_name << "\" was destroyed." << std::endl;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hit = src.getHit();
		this->_energy = src.getEnergy();
		this->_damage = src.getDamage();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string & target) {
	if (this->_hit == 0) {
		std::cout <<  "ScavTrap " << this->_name
			<< " can't attack: no hit point."  << std::endl;
		return ;
	}
	if (this->_energy == 0) {
		std::cout << "ScavTrap " << this->_name
			<< " can't attack: no energy point." << std::endl;
		return ;
	}
	_energy--;
	std::cout <<  "ScavTrap " << this->_name
		<< " leaps on " << target << " and crushes it for " << this->_damage
		<< " damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (this->_guard == false)
  {
    this->_guard = true;

		std::cout <<  "ScavTrap " << this->_name
			<< "is now in Gate keeper mode." << std::endl;
  }
	else
		std::cout << "ScavTrap " << this->_name
			<< " is already in Gate keeper mode." << std::endl;
	return ;
}
