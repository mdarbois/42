#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_trap") {
	std::cout <<  "DiamondTrap default constructor called."  << std::endl;
	this->_name = "default";
  this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap") {
	this->_name = name;
  std::cout <<  "A DiamondTrap named \"" << name << "\" was constructed." << std::endl;
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "DiamondTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout <<  "The DiamondTrap named \"" << this->_name << "\" was destroyed." << std::endl;
	return ;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & src) {
	std::cout << "Diamond Trap copy assignment operator called" << std::endl;
  if (this != &src) {
		this->_name = src.getName() + "_clap_trap";
		this->_hit = src.getHit();
		this->_energy = src.getEnergy();
		this->_damage = src.getDamage();
	}
	return (*this);
}


void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello my DiamondTrap name is " << this->_name <<
	" and i am originated from the ClapTrap named " << ClapTrap::_name << "." <<
	std::endl;
}
