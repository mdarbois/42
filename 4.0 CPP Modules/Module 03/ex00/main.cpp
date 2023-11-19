#include "ClapTrap.hpp"
#include <string>

int	main(void) {
  std::string name1 = "Trap1";
	std::string name2 = "Trap2";
  ClapTrap trap1(name1);
  ClapTrap trap2(name2);

  trap2.beRepaired(0);


    trap1.attack(name2);
    trap2.takeDamage(3);
    trap2.beRepaired(2);
    trap2.attack(name1);
    trap1.takeDamage(42);
    trap1.beRepaired(500);
    trap2.beRepaired(500);
    trap2.attack(name2);
    trap2.takeDamage(500);
    trap2.beRepaired(500);
    trap2.takeDamage(3);
    return (0);

  }
