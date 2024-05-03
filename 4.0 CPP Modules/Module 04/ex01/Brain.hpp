#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain {
    
    protected:
        std::string _ideas[100];

    public:
        Brain( void );
        Brain (Brain const &src);
        Brain &operator=(Brain const &rhs);
        ~Brain( void );

};
#endif