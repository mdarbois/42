#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
	return ;
}

template <typename T>
T const & min(const T& a, const T& b)
{
   if(a<b)
      return a;
   else
      return b;
}
template <typename T>
T const & max(const T& a, const T& b)
{
   if(a>b)
      return a;
   else
      return b;
}

#endif