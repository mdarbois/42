#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


void	testIntern(std::string formName, std::string target)
{
	std::cout << std::endl << "---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	intern = Intern();
	Bureaucrat boss("Boss", 1);
	AForm *	form;
	try
	{
		form = intern.makeForm(formName, target);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << ": " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::string const	shrubberyFormName = "shrubbery creation";
	std::string const	robotomyFormName = "robotomy request";
	std::string const	presidentialFormName = "presidential pardon";

	testIntern(shrubberyFormName, "Home");
	testIntern(robotomyFormName, "Alex");
	testIntern(presidentialFormName, "Leon");
	testIntern("Bad Form Name", "Marco");
	testIntern("", "");	
	return (0);
}