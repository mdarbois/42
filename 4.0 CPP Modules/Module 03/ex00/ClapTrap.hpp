#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {

  private:
    std::string _name;
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _damage;

  public:
    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap (ClapTrap const &src);
    ClapTrap &operator=(ClapTrap const &rhs);
		~ClapTrap( void );

    std::string		getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
