#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack<T>() : std::stack<T>() {};
        MutantStack<T> (MutantStack const &src) : std::stack<T>(src) {};
        MutantStack<T> &operator=(MutantStack const &rhs) {
            if (this != &rhs)
				this->c = rhs.c;
			return (*this);
        }
        ~MutantStack<T>() {};

        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;


        MutantStack<T>::iterator begin (void) {
            return (this->c.begin());
        }
        MutantStack<T>::iterator end (void){
            return (this->c.end());
        }
        MutantStack<T>::const_iterator begin (void) const {
            return (this->c.begin());
        }
        MutantStack<T>::const_iterator end (void) const {
            return (this->c.end());
        }
        MutantStack<T>::reverse_iterator rbegin (void) {
            return (this->c.rbegin());
        }
        MutantStack<T>::reverse_iterator rend (void) {
            return (this->c.rend());
        }
        MutantStack<T>::const_reverse_iterator rbegin (void) const {
            return (this->c.rbegin());
        }
        MutantStack<T>::const_reverse_iterator rend (void) const {
            return (this->c.rend());
        }

};
#endif