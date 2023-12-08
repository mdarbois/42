#include "Form.hpp"

Form::Form() : _name("Default form"), _signed(false), _gradeSign(1), _gradeExecute(1){
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int const gradeSign, int const gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    std::cout << "Fancy form constructor called" << std::endl;
    if (gradeSign > 150 || gradeExecute > 150)
        throw(Form::GradeTooLowException());
    if (gradeSign < 1 || gradeExecute < 1)
        throw(Form::GradeTooHighException());
    return ;
}

Form::Form(Form const &src): _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(Form const &rhs)
{
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
  std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string const & Form::getName() const
{
    return (this->_name);
}
bool Form::getSigned() const
{
    return (this->_signed);
}
int  Form::getGradeSign() const
{
    return (this->_gradeSign);
}
int  Form::getGradeExecute() const
{
    return (this->_gradeExecute);
}

void Form::beSigned(Bureaucrat  const &bureaucrat)
{
    if(this->_signed == true)
        throw (Form::AlreadySignedException());
    if (bureaucrat.getGrade() > this->_gradeSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
	return ;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

std::ostream& operator<<( std::ostream &flux, Form const& form )
{
    flux << form.getName() << ", form grade to sign: " << form.getGradeSign() << ", form grade to execute: "  << form.getGradeExecute() << "." << std::endl;
    return (flux);
}