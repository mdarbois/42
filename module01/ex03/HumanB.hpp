#ifndef __HUMAN_B_HPP__
#define __HUMAN_B_HPP__

#include "Weapon.hpp"

class HumanB {

  public:
      HumanB( std::string const aName );
      ~HumanB( void );
      void attack( void );
      void	setWeapon(Weapon &aWeapon);

  private:
    Weapon *_weapon;
    std::string const _name;

};

#endif
