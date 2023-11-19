#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
	public:
    ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &operator=(ScavTrap const & src);

		void	attack(const std::string & target);
		void	guardGate(void);

	private:
		bool _guard;
};

#endif
