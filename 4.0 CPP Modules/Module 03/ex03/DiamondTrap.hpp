#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;

  public:
    DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap(DiamondTrap const & src);
		virtual ~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const & src);

    void	attack(const std::string & target);

    void whoAmI();

};

#endif
