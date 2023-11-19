#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

int	main(void) {
{
  std::cout << "TESTING CLAPTRAP" << std::endl;

  ClapTrap	a("CLAP-0");
  ClapTrap	b("CLAP-1");
  a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("CLAP-1-clone");
	b.beRepaired(3);
}
{
  std::cout << "TESTING SCAVTRAP" << std::endl;

	ScavTrap	c("SCAV-0");
  ScavTrap	d("SCAV-1");

    c.attack("CloneScav");

		c.takeDamage(21);

		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
}
{
  std::cout << "TESTING FRAGTRAP" << std::endl;

	FragTrap	e("FRAG-0");
  FragTrap	f("FRAG-1");

    e.highFivesGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFivesGuys();
		f.attack("FragTrap-clone");
}
	return (0);
}
