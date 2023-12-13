#ifndef	ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>


template <typename T, typename U>
void	iter(T * array, size_t length, U function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
	return ;
}

template <typename U>
void	increment(U & nb)
{
	nb += 1;
	return ;
}

template <typename T>
void	display(T * array, size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << i << " = " << array[i] << "\t";
	std::cout << std::endl;
}

#endif