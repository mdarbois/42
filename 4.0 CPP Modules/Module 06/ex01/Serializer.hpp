#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <stdint.h>

struct Data
{
	unsigned int	value;
	std::string		string;
};

class Serializer
{
    public:
        
        Serializer (Serializer const &src);
        Serializer &operator=(Serializer const &rhs);
        ~Serializer();

   static uintptr_t serialize(Data* ptr);
    // It takes a pointer and converts it to the unsigned integer type uintptr_t.
    static Data* deserialize(uintptr_t raw);
        //It takes an unsigned integer parameter and converts it to a pointer to Data
    private:
        Serializer();
};



std::ostream &	operator<<(std::ostream &stream, Data const  & obj);
#endif