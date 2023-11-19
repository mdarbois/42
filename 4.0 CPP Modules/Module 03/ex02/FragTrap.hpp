#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
    FragTrap( void );
		FragTrap( std::string name );
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &operator=(FragTrap const & src);

    void highFivesGuys(void);
};

#endif
