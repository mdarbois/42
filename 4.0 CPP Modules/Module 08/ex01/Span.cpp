#include "Span.hpp"

Span::Span() : _range(), _size(0)
{
    std::cout << "Span default constructor called" << std::endl;
    return ;
}

Span::Span(unsigned int N) : _range(), _size(N)
{
    std::cout << "Fancy span constructor called" << std::endl;
}

Span::Span (Span const &src) : _range(src._range), _size(src._size) 
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(Span const &rhs)
{
    if (this != &rhs) {
        this->_size = rhs.getSize();
        this->_range.clear();
		this->_range.insert(this->_range.end(),rhs._range.begin(), rhs._range.end());
    }
  std::cout << "Span copy assignment operator called" << std::endl;
    return *this;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

unsigned int const & Span::getSize() const
{
    return (this->_size);
}

std::vector<int> const &	Span::getRange(void) const
{
	return (this->_range);
}

void Span::addNumber(int nb)
{
    if (this->_range.size() == this->_size)
		throw (Span::ClassIsFullException());
	this->_range.push_back(nb);
	return ;
}

unsigned int	Span::shortestSpan(void) const
{
	int	shortest;

	if (this->_range.size() <= 1)
		throw (Span::ClassIsEmptyOrOneException());

	std::vector<int>	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());

	std::vector<int>	span(sorted);
	std::adjacent_difference(sorted.begin(), sorted.end(), span.begin());
	shortest = *std::min_element((span.begin()), span.end());
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_range.size() <= 1)
		throw (Span::ClassIsEmptyOrOneException());
	unsigned int max = *std::max_element(this->_range.begin(), this->_range.end());
	unsigned int min = *std::min_element(this->_range.begin(), this->_range.end());
	return (max - min);
}

const char *	Span::ClassIsFullException::what(void) const throw()
{
	return ("Span class is full, can't add any new numbers.");
}

const char *	Span::ClassIsEmptyOrOneException::what(void) const throw()
{
	return ("Span class is empty or contains only one element, can't find any span.");
}

std::ostream &	operator<<(std::ostream &os, Span &obj)
{
    std::cout << "Size is:" << obj.getSize() << std::endl;
    for (std::vector<int>::const_iterator it = obj.getRange().begin();
			it != obj.getRange().end(); ++it)
		std::cout << "[" << *it << "] ";
    return (os);
}