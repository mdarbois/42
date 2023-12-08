
#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"


void	TestForm(std::string name, int gradeSign, int gradeExecute)
{
	std::cout << std::endl << "-- Form named \""
		<< name << "\" with grade to sign " << gradeSign
		<< " and grade to execute " << gradeExecute << ":" << std::endl;
	try
	{
		Form	form(name, gradeSign, gradeExecute);
		std::cout << form << " successfully created." << std::endl;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << "---- TEST FORM DEFAULT CONSTRUCTOR" << std::endl;
	{
		Form form;
		std::cout << "Default form is: " << form << std::endl;
	}
	
	std::cout << std::endl << "---- TEST FORM ATTRIBUTE CONSTRUCTOR" << std::endl;
	TestForm("Simple Form", 42, 42);
	TestForm("Working Form", 150, 1);
	TestForm("Unsignable Form", 151, 1);
	TestForm("Unexecutable Form", 1, 0);
	TestForm("Unexecutable Form", -10, 140);
	{
		std::cout << std::endl << "---- TEST FORM COPY CONSTRUCTOR" << std::endl;
		Form form("FormABC", 42, 42);
		std::cout << "Form is " << form << std::endl;
		Form formCopy(form);
		std::cout << "Form copy is " << formCopy << std::endl;
	}
	{
		std::cout << std::endl << "---- TEST FORM ASSIGNMENT OPERATOR" << std::endl;
		Bureaucrat	bureaucrat("Marco", 42);
		Form form1("Form #1", 150, 1);
		Form form2("Form #2", 42, 42);

		std::cout << "Two forms created:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		bureaucrat.signForm(form2);
		std::cout << "Form 2 signed:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		form1 = form2;
		std::cout << "First form = second form:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		bureaucrat.signForm(form1);
	}
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT FORM SIGNING" << std::endl;
		Bureaucrat	Alex("Alex", 150);
		Bureaucrat	Leon("Leon", 42);
		Bureaucrat	Theo("Theo", 1);

		Form	minForm("Mini Form", 150, 150);
		Form	middleForm("Middle Form", 42, 42);
		Form	maxForm("Maxi Form", 1, 1);

		std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << Alex << "\n"
			"\t" << Leon << "\n"
			"\t" << Theo << std::endl;

		std::cout << std::endl << "Attempting to sign " << minForm << ":" << std::endl;
		Alex.signForm(minForm);
		Leon.signForm(minForm);
		Theo.signForm(minForm);
		std::cout << std::endl;

		std::cout << std::endl << "Attempting to sign " << middleForm << ":" << std::endl;
		Alex.signForm(middleForm);
		Leon.signForm(middleForm);
		Theo.signForm(middleForm);
		std::cout << std::endl;
	
		std::cout << std::endl << "Attempting to sign "	<< maxForm << ":" << std::endl;
		Alex.signForm(maxForm);
		Leon.signForm(maxForm);
		Theo.signForm(maxForm);
		std::cout << std::endl;
	}
	return (0);
}