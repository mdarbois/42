#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {

    private:
        std::string const _name;
        bool _signed;
        int const _gradeSign;
        int const _gradeExecute;
    public:
        AForm();
        AForm(std::string const & name, int gradeSign, int gradeExecute);
        AForm (AForm const &src);
        AForm &operator=(AForm const &rhs);
	    ~AForm();

        std::string const &getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        void execute(Bureaucrat const & bureaucrat) const;

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
        class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	protected:
		virtual void	beExecuted(void) const = 0;
};

std::ostream& operator<<(std::ostream &flux, AForm const& form );


#endif