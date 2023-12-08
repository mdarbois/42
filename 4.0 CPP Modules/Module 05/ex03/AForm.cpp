#include "AForm.hpp"

AForm::AForm() : _name("Default form"), _signed(false), _gradeSign(1), _gradeExecute(1){
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int const gradeSign, int const gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    std::cout << "Fancy aform constructor called" << std::endl;
    if (gradeSign > 150 || gradeExecute > 150)
        throw(AForm::GradeTooLowException());
    if (gradeSign < 1 || gradeExecute < 1)
        throw(AForm::GradeTooHighException());
    return ;
}

AForm::AForm(AForm const &src): _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(AForm const &rhs)
{
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
  std::cout << "AForm copy assignment operator called" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;

}

std::string const & AForm::getName() const
{
    return (this->_name);
}
bool AForm::getSigned() const
{
    return (this->_signed);
}
int  AForm::getGradeSign() const
{
    return (this->_gradeSign);
}
int  AForm::getGradeExecute() const
{
    return (this->_gradeExecute);
}

void AForm::beSigned(Bureaucrat  const &bureaucrat)
{
    if(this->_signed == true)
        throw (AForm::AlreadySignedException());
    if (bureaucrat.getGrade() > this->_gradeSign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (this->_signed == false)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_gradeExecute)
		throw (AForm::GradeTooLowException());
	this->beExecuted();
	return ;
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("AForm is already signed.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}

std::ostream& operator<<( std::ostream &flux, AForm const& aform )
{
    flux << aform.getName() << ", aform grade to sign: " << aform.getGradeSign() << ", aform grade to execute: "  << aform.getGradeExecute() << "." << std::endl;
    return (flux);
}