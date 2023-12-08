#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include <exception>
# include "Form.hpp"

class Form;
class Bureaucrat {
    
private:
    std::string const _name;
    int   _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat (Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat();

    std::string const &getName() const;
    int getGrade() const;
    void increment();
    void decrement();

    void	signForm(Form & form) const;

    class GradeTooHighException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &flux, Bureaucrat const& bureaucrat );


#endif