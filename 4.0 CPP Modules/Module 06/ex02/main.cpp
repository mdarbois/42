
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"


Base *	generate(void)
{
	int	num = std::rand() % 3;
    Base	*base = NULL;
    try
	{
        if (num == 0)
        {
            std::cout << "Generated: A" ;
            base = dynamic_cast<Base *>(new A);
        }
        if (num == 1)
        {
                std::cout << "Generated: B" ;
                base = dynamic_cast<Base *>(new B);
        }
        if (num == 2)
        {
            std::cout << "Generated: C" ;
            base = dynamic_cast<Base *>(new C);
        }
        return (base);
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
    return (base);
}

void	identify(Base * p)
{
	std::cout << "Pointer: ";
    try
	{
        if (dynamic_cast<A *>(p))
            std::cout << "A" ;
        else if (dynamic_cast<B *>(p))
            std::cout << "B" ;
        else if (dynamic_cast<C *>(p))
            std::cout << "C" ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	identify(Base & p)
{
	std::cout << "Reference: ";
	try
	{
        if(dynamic_cast<A *>(&p))
		    std::cout << "A";
		else if(dynamic_cast<B *>(&p))
		    std::cout << "B";
        else if(dynamic_cast<C *>(&p))
		    std::cout << "C";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	Base *	p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 25; i++)
	{
		std::cout << "Test [" << i << "]:\t";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}