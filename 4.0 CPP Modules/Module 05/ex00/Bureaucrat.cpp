#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Fancy bureaucrat constructor called" << std::endl;
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else
        this->_grade = grade;
    return ;
}

Bureaucrat::Bureaucrat (Bureaucrat const &src) : _name(src._name), _grade(src._grade) 
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs) {
		//this->_name = rhs.getName();
        this->_grade = rhs.getGrade();
    }
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;

}
std::string const & Bureaucrat::getName() const
{
    return (this->_name);
}
int Bureaucrat::getGrade() const
{
    return (this->_grade);
}
void Bureaucrat::increment()
{
    if (this->_grade - 1 < 1)
        throw(Bureaucrat::GradeTooHighException());
    else
    {
        this->_grade -= 1;
        std::cout << *this << "Bureaucrat got its grade incremented, now: " << this->_grade << std::endl;
    }
    return;
}

void Bureaucrat::decrement()
{
    if (this->_grade + 1 > 150)
        throw(Bureaucrat::GradeTooLowException());
       else
    {
        this->_grade += 1;
        std::cout << *this << "Bureaucrat got its grade decremented, now: " << this->_grade << std::endl;
    }
    return;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade is too high.");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grade is too low.");
}

std::ostream& operator<<( std::ostream &flux, Bureaucrat const& bureaucrat )
{
    flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return (flux);
}