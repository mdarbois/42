#ifndef	SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <vector>
# include <list>
# include <iostream>
# include <limits>
# include <numeric>

class Span 
{
    private:
        std::vector<int> _range;
        unsigned int _size;

    public:
        Span();
        Span(unsigned int N);
        Span (Span const &src);
        Span &operator=(Span const &rhs);
        ~Span();

        void addNumber(int nb);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        unsigned int const & getSize() const;
        std::vector<int> const & getRange() const;
        class ClassIsFullException: public std::exception {
            public:
            virtual const char* what() const throw();
        };
        class ClassIsEmptyOrOneException: public std::exception {
            public:
            virtual const char* what() const throw();
        };
        template <typename T>
		void	addRange(typename T::iterator & begin, typename T::iterator & end)
		{
			unsigned int	span = std::distance(begin, end);
			
			if (span > (this->_size - this->_range.size()))
				throw (Span::ClassIsFullException());
			else if (span != 0)
				this->_range.insert(this->_range.end(), begin, end);
			return ;
		}
};

std::ostream &	operator<<(std::ostream &os, Span &obj);

#endif