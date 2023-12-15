#ifndef	BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange 
{
    private:

        std::map<std::string, double> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &file);
        BitcoinExchange (BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();

        void calculate(const std::string &file);
        bool checkDate(const std::string &date);
	    bool checkValue(const double &value);
        double priceDay(const std::string &date);
};

#endif