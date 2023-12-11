#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

# include <cctype>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

class ScalarConverter {

    public:
        ScalarConverter (ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter();

        static void convert(std::string input);
    private:
        ScalarConverter();

};
#endif