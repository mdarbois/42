#include "Span.hpp"

void	multipleAdditions(Span & sp, unsigned int size);

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
		std::cout << "TEST 2" << std::endl;
		Span sp(10);
		::multipleAdditions(sp, 10);
    try
	{
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}  
		::multipleAdditions(sp, 10);
	try
	{
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}
		::multipleAdditions(sp, 10);
		try
	{
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}
	}
return 0;
}



void	multipleAdditions(Span & sp, unsigned int size)
{
	std::list<int>	addition;
	for (unsigned int i = 0; i < size / 2; i++)
		addition.push_back(std::rand() % 1000);
	
	std::list<int>::iterator begin = addition.begin();
	std::list<int>::iterator end = addition.end();

	std::cout << "Adding numbers: ";
	for (std::list<int>::iterator it = begin; it != end; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl;

	try
	{
		sp.addRange<std::list<int> >(begin, end);
		std::cout <<  "OK. Range added" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: Cannot add range of " << size / 2 
			<< " numbers: " << e.what() << std::endl << std::endl;
	}
}