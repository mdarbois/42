#include "iter.hpp"
#include <string>
#include <cmath>

int main(void)
{
    {
		std::cout << "EMPTY ARRAY" << std::endl;
		
		int	array[] = {};
		size_t	size = 0;

		std::cout << "Empty int array:\t\t";
		::display<int>(array, size);

		::iter<int>(array, size, ::increment<int>);
		
		std::cout << "Empty int array incremented:\t";
		::display<int>(array, size);
	}
    {
		std::cout << std::endl << "INT ARRAY" << std::endl;
		
		int	array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		size_t	size = 10;

		std::cout << "Int array:\t\t";
		::display<int>(array, size);

		::iter<int>(array, size, ::increment<int>);
		
		std::cout << "Int array incremented:\t";
		::display<int>(array, size);
	}
    {
		std::cout << std::endl << "DOUBLE ARRAY" << std::endl;
		
		double array[] = {0.5, -5.736, 14.5, 42.0};
		size_t	size = 4;
		
		std::cout << "Double array:\t\t\t";
		::display<double>(array, size);
		
		::iter<double>(array, size, ::increment<double>);
		
		std::cout << "Double array incremented:\t";
		::display<double>(array, size);
	}
    {
		std::cout << std::endl << "CHAR ARRAY" << std::endl;
		
		char array[] = {'a', 'b', 'c', 'd', 'e'};
		size_t	size = 5;
		
		std::cout << "Char array:\t\t\t";
		::display<char>(array, size);
		
		::iter<char>(array, size, ::increment<char>);
		
		std::cout << "Char array incremented:\t\t";
		::display<char>(array, size);
    }
    return (0);
}