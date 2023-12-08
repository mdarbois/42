#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__


#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

        std::string const &	getTarget(void) const;
		void	beExecuted(void) const;

    private:
		std::string	_target;
};
#endif