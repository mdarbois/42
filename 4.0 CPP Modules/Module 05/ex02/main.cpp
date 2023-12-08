#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	badBureaucrat("Bad", 142);
	Bureaucrat	middleBureaucrat("Middle", 65);
	Bureaucrat	goodBureaucrat("Good", 6);

	std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << badBureaucrat << "\n"
			"\t" << middleBureaucrat << "\n"
			"\t" << goodBureaucrat << std::endl << std::endl;
	
	ShrubberyCreationForm	shrubForm("Shrub");
	RobotomyRequestForm		robotomyForm("Robotomy");
	PresidentialPardonForm	pardonForm(goodBureaucrat.getName());

	std::cout << std::endl << "Three forms created:\n"
			"\t" << shrubForm << "\n"
			"\t" << robotomyForm << "\n"
			"\t" << pardonForm << std::endl;

	std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
	badBureaucrat.signForm(shrubForm);
	badBureaucrat.executeForm(shrubForm);
	middleBureaucrat.executeForm(shrubForm);

	std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
	middleBureaucrat.executeForm(robotomyForm);
	middleBureaucrat.signForm(robotomyForm);
	middleBureaucrat.executeForm(robotomyForm);
	goodBureaucrat.executeForm(robotomyForm);

	std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
	goodBureaucrat.executeForm(pardonForm);
	goodBureaucrat.signForm(pardonForm);
	goodBureaucrat.executeForm(pardonForm);
	goodBureaucrat.increment();
	goodBureaucrat.executeForm(pardonForm);

	std::cout << std::endl;
	return (0);
}