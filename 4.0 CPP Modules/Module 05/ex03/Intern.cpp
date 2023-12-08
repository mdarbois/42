#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern (Intern const &src)
{
    (void)src;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(Intern const &rhs)
{
    (void)rhs;
  std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm    *createPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm    *createRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm    *createShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}

AForm *	Intern::makeForm(const std::string formName, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};
	std::string forms[] = {"shrubbery creation",  "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern could not create form named \""
		<< formName << "\"";
	throw Intern::InvalidFormName();
}