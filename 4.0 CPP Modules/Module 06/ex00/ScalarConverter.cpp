#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter (ScalarConverter const &src)
{
	(void)src;
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
    std::cout << "ScalarConverter assignment operator overload called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

static void	printConvert(double nbDouble) {
	char nbChar = static_cast<char>(nbDouble);
	int nbInt = static_cast<int>(nbDouble);
	float nbFloat = static_cast<float>(nbDouble);

	std::cout << "char: ";
	if (std::isnan(nbDouble) || nbDouble > std::numeric_limits<char>::max() || nbDouble < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else {
		if (!std::isprint(nbChar))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << nbChar << "'" << std::endl;
	}

	std::cout << "int: ";
	if (std::isnan(nbDouble) || nbDouble > std::numeric_limits<int>::max() || nbDouble < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << nbInt << std::endl;


	std::cout << "float: ";
	if (!std::isinf(nbDouble) && (nbDouble > std::numeric_limits<float>::max() || nbDouble < -std::numeric_limits<float>::max() || std::isnan(nbDouble)))
		std::cout << "nanf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << nbFloat << "f" << std::endl;


	std::cout << "double: " << std::fixed << std::setprecision(1) << nbDouble << std::endl;
}


void	ScalarConverter::convert(std::string input) {
	double	nbDouble;
	char *endptr;
	if (input.length() == 1 && !std::isdigit(input[0]))
		nbDouble = input[0];
	else if (input == "-inf" || input == "-inff")
		nbDouble = -std::numeric_limits<double>::infinity();
	else if (input == "+inf" || input == "+inff")
		nbDouble = std::numeric_limits<double>::infinity();
	else if (input == "nan")
		nbDouble = std::numeric_limits<double>::quiet_NaN();
	else {
		if (input[input.length() - 1] == 'f')
			input.erase(input.end() - 1, input.end());
		nbDouble = std::strtod(input.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Conversion failed." << std::endl;
			return ;
		}
	}
	printConvert(nbDouble);
}