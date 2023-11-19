#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Default"),
           _hit(10), _energy(10), _damage(0) {
  std::cout << "Clap Trap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),
           _hit(10), _energy(10), _damage(0) {
  std::cout << "Clap Trap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src){
  std::cout << "Clap Trap copy constructor called" << std::endl;
  *this = src;
  return ;
}


ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
  std::cout << "Clap Trap copy assignment operator called" << std::endl;
  if (this != &rhs)
  {
    this->_name = rhs.getName();
    this->_hit = rhs.getHit();
		this->_energy= rhs.getEnergy();
		this->_damage = rhs.getDamage();
	}
  return *this;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Clap Trap destructor called" << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHit(void) const {
	return (this->_hit);
}

unsigned int	ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

unsigned int	ClapTrap::getDamage(void) const {
	return (this->_damage);
}


void	ClapTrap::attack(const std::string & target) {
	if (this->_hit == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't attack: no hit point." << std::endl;
		return ;
	}
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name
      << " can't attack: no energy point." << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
    << " causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't take anymore damage: it is already beyond repair!" << std::endl;
		return;
	}
	if ((int)this->_hit - (int)amount <= 0) {
		this->_hit = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount
      << " damage and is destroyed!"  << std::endl;
	}
	else {
		this->_hit -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount
      << " damage!"  << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't repair itself: no hit point." << std::endl;
		return ;
	}
	if (this->_energy == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't repair itself: no energy point." << std::endl;
		return ;
	}
	if ((this->_hit + amount) > 10)
	{
		this->_energy--;
		std::cout << "ClapTrap " << this->_name
			<< " wastes energy trying to repair itself when it is already full of hit points."
			 << std::endl;
		return ;
	}
	this->_energy--;
	this->_hit += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for "
		<< amount << "." << std::endl;
	return ;
}
