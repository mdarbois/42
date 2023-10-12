#ifndef __HUMAN_A_H__
#define __HUMAN_A_HPP__

#include "Weapon.hpp"

class HumanA
{
  public:
      HumanA( std::string const aName, Weapon const &aWeapon );
      ~HumanA( void );
      void attack ( void );

  private:
      std::string const _name;
      Weapon const &_weapon;
};
#endif
