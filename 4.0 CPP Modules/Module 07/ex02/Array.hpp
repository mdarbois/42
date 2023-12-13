#ifndef	ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

template <typename T = int>
class Array 
{
    private:
		T *				_array;
		unsigned int	_size;

    public:
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int n) : _array(new T[n]), _size(n) {}
        Array(Array const & src) :_array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
        Array &operator=(Array const & src)  {
			if (this == &src)
				return (*this);
			if (this->_size != src._size) {
				delete [] _array;
				this->_size = src._size;
				this->_array = new T[this->_size];
			}
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}
        ~Array(void) { delete [] _array; }

        T &	operator[](unsigned int index) {
			if (index >= this->_size)
				throw (OutException());
			return (this->_array[index]);
		}

        unsigned int size() const {
            return (this->_size);
        }

        class OutException : public std::exception {
			public:
				virtual char const *	what(void) const throw() {
					return ("Index out of bounds");
				}
		};
    
};

template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &obj) {
    for (unsigned int i = 0; i < obj.size(); ++i) {
        os << "[" << obj[i] << "] ";
    }
    return (os);
}
#endif