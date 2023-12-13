#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

template <typename T>
void	test(std::string containerType, T & container, int occurence);

int main(void)
{
    {
		std::cout << std::endl << "LIST CONTAINER" << std::endl;
        std::list<int>	container;

		std::cout << "List: ";
        for (int i = -2; i < 35; i++)
			container.push_front(i * 10 + i);
		for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
        ::test("List", container, 0);
		::test("List", container, 88);
		::test("List", container, -13);
		::test("List", container, 242);
		::test("List", container, -22);
		::test("List", container, 35);
		::test("List", container, 16);
    }
    {
		std::cout << std::endl << "DEQUE CONTAINER" << std::endl;
        std::deque<int>	container;
        std::cout << "Deque: ";
        for (int i = 0; i < 15; i++)
			container.push_back(i * 100 + 3);
		for (std::deque<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::test("Deque", container, 0);
        ::test("Deque", container, 5);
		::test("Deque", container, 603);
		::test("Deque", container, -358);
		::test("Deque", container, -3);
		::test("Deque", container, 403);
		::test("Deque", container, 1203);
		::test("Deque", container, 103);
    }
	{
		std::cout << std::endl << "VECTOR CONTAINER" << std::endl;
		
		std::vector<int>	container;
        std::cout << "Vector: ";
        for (int i = -5; i < 10; i++)
			container.push_back(i * 2);
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
        ::test("Vector", container, 0);
		::test("Vector", container, 9);
		::test("Vector", container, -6);
		::test("Vector", container, 42);
		::test("Vector", container, -2);
		::test("Vector", container, 25);
		::test("Vector", container, 18);
    }
}

template <typename T>
void	test(std::string containerType, T & container, int occurence)
{
	std::cout << std::endl << "Looking for: " << occurence << std::endl;
	bool	found = false;
	int		result = 0;

	std::cout << containerType << " container: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == occurence && found == false)
		{
			found = true;
		}
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
	try
	{
		result = *(::easyfind(container, occurence));
		if (found == false)
			std::cout << "KO: found " << result << std::endl;
		else
			std::cout << "OK: found " << result << ", as expected." << std::endl;
	}
	catch (std::exception & e)
	{
		if (found == false)
			std::cout << "OK exception: " << e.what() << std::endl;
		else
			std::cout << "KO exception is wrong:" << e.what() << std::endl;
	}
}