#include <cstdlib>
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) :AForm("Robotomy Request Form", 145, 137), _target("Unknown")
{
        std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy Request Form", 72, 45),	_target(target)
{
      std::cout << "Fancy RobotomyRequestForm constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :	AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
     if (this != &src) {
	this->_target = src._target;
       }
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beExecuted(void) const
{
    std::cout << "... drilling noises... " << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
	return ;
}