#include "Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer (Serializer const &src)
{
    *this = src;
    std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(Serializer const &rhs)
{
    (void)rhs;
    std::cout << "Serializer copy assignment operator called" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;

}

uintptr_t	Serializer::serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &	operator<<(std::ostream & os,  Data const& obj)
{
	os << "Data structure stored at address [" << &obj << "]"
		<< "\n\t- value : " << obj.value
		<< "\n\t- string: " << obj.string << std::endl;
	return (os);
}