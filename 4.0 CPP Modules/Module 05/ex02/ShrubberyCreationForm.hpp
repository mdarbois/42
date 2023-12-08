#ifndef __SHRUBBERY_CREATION_FORM_HPP__
#define __SHRUBBERY_CREATION_FORM_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

        std::string const &	getTarget(void) const;
		void	beExecuted(void) const;

    private:
		std::string	_target;
		static std::string const _tree;
};
#endif