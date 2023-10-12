#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie {

  public:

    void announce( void );
    Zombie( std::string name );
    ~Zombie( void );
    std::string getName( void );

  private:

    std::string _name;
};

#endif
