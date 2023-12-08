
#include "Bureaucrat.hpp"
#include <iostream>


void	Test(std::string name, int grade)
{
	std::cout << std::endl << "-- Bureaucrat named \""
		<< name << "\" with grade " << grade << ":" << std::endl;
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << " successfully created." << std::endl;
		return ;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cerr <<"Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{

	std::cout << std::endl << "---- TEST BUREAUCRAT DEFAULT CONSTRUCTOR" << std::endl;
	{
		Bureaucrat	bureaucrat;
		std::cout << "Default bureaucrat is: " << bureaucrat << std::endl;
	}

	std::cout << std::endl << "---- TEST BUREAUCRAT NAME/GRADE CONSTRUCTORS" << std::endl;
	Test("Leon", 20);
	Test("Alex", 150);
	Test("Theo", 1);
	Test("Marco", 0);
	Test("Chantal", 151);
	Test("Jamie", -10);

	{
		std::cout << std::endl << "---- TEST BUREAUCRAT ASSIGNMENT OPERATOR" << std::endl; 
		Bureaucrat bureaucrat1("Carol", 150);
		Bureaucrat bureaucrat2("Maxime", 42);

		std::cout << "Two bureaucrats created:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
		
		bureaucrat1 = bureaucrat2;
		std::cout << "First bureaucrat = second bureaucrat:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
	}
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT GRADE INCREMENT/DECREMENT" << std::endl;
		Bureaucrat bureaucrat("Sam", 2);
		std::cout << "Bureaucrat created:\n"
			"\t" << bureaucrat << std::endl;
		try
		{
			std::cout << "Decrementing grade by 1 -> result should be " << bureaucrat.getGrade() + 1 << ":" << std::endl;
			bureaucrat.decrement();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.increment();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.increment();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.increment();
			std::cout << bureaucrat << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cout <<"Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}