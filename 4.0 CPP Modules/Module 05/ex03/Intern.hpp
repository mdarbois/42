#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern (Intern const &src);
        Intern &operator=(Intern const &rhs);
        ~Intern();

        AForm* makeForm(const std::string formName, const std::string target);

        class InvalidFormName : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

    
    };


#endif