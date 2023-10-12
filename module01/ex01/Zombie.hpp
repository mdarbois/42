#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie {

  public:

    void announce( void );
    Zombie( void );
    Zombie( std::string name );
    ~Zombie( void );
    std::string getName( void ) const;
    void setName( std::string const name );

  private:

    std::string _name;
};

#endif
