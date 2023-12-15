#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    std::ifstream ifs;
    if (argc != 2)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return (1);
    }
    BitcoinExchange bte("data.csv");
    ifs.open(argv[1]);
    if (ifs.fail())
    {
		std::cout << "Error: " << argv[1] << ": no such file" << std::endl;
		return (1);
	}
    bte.calculate(argv[1]); 
    return (0);
    
}