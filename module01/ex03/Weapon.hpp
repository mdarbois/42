#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon {

  public:
    Weapon( std::string const type );
		~Weapon( void );
		std::string const	&getType( void ) const;
		void				setType( std::string const type );

  private:
    std::string _type;
};

#endif
