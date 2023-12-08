#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {

    private:
        std::string const _name;
        bool _signed;
        int const _gradeSign;
        int const _gradeExecute;
    public:
        Form();
        Form(std::string const & name, int gradeSign, int gradeExecute);
        Form (Form const &src);
        Form &operator=(Form const &rhs);
	    ~Form();

        std::string const &getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream &flux, Form const& form );


#endif