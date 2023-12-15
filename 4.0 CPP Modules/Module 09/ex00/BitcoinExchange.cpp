#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
    return ;
}

BitcoinExchange::BitcoinExchange(const std::string &file)
{
    std::cout << "Fancy BitcoinExchange constructor called" << std::endl;
    std::ifstream ifs(file.c_str());
	std::string line;
	std::getline(ifs, line); 
	while (std::getline(ifs, line)) 
    {
        std::string::size_type sep = line.find(',');
        if (sep == std::string::npos) 
        {
			std::cerr << "Error: Invalid format :" << line << std::endl;
			continue;
		}
        std::string date_string = line.substr(0, sep);
		std::string value_string = line.substr(sep + 1);
        std::istringstream value_stream(value_string);
        double value;
        value_stream >> value;
        if (value_stream.fail()) 
        {
            std::cerr << "Failed to extract data.csv: " << line << std::endl;
            continue;
        }
        _database[date_string] = value;
    }
}

BitcoinExchange::BitcoinExchange (BitcoinExchange const &src)
{
    this->_database = src._database;
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs) {
        this->_database = rhs._database;
    }
  std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

double BitcoinExchange::priceDay(const std::string &date)
{
	std::map<std::string, double>::iterator it = _database.begin();
	for (; it != _database.end(); it++)
		if (it->first.compare(date) == 0) 
			return it->second;
	it = _database.lower_bound(date);
	if (it == _database.begin()) 
		return -1.0;
	it--;
	return it->second;
}

bool BitcoinExchange::checkDate(const std::string& date) {
	std::string::size_type sep1 = date.find('-');
	std::string::size_type sep2 = date.rfind('-');

	if (sep1 == std::string::npos || sep1 == sep2)
		return false;

	std::string year_string = date.substr(0, sep1);
	std::string month_string = date.substr(sep1 + 1, sep2 - sep1 - 1);
	std::string day_string = date.substr(sep2 + 1);

    if (year_string.find_first_not_of("0123456789") != std::string::npos){
        return false;
    }
    if (month_string.find_first_not_of("0123456789") != std::string::npos){
        return false;
    }
    if (day_string.find_first_not_of("0123456789") != std::string::npos){
        return false;
    }
	int year, month, day;
	std::istringstream year_stream(year_string), month_stream(month_string), day_stream(day_string);
    year_stream >> year;
    month_stream >> month;
    day_stream >> day;
	if (year_stream.fail() || month_stream.fail() || day_stream.fail())
		return false;

	if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}
	if (month == 2) {
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((leap && day > 29) || (!leap && day > 28)) {
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::checkValue(const double &value) {
	if (value < 0 || value > 1000) {
		std::cerr << "Error: " << value << " must be a positive number (float or int) between 0 and 1000.\n";
		return false;
	}
	return true;
}

void BitcoinExchange::calculate(const std::string &file)
{
    std::ifstream ifs(file.c_str());
	std::string line;
	std::getline(ifs, line); 
	while (std::getline(ifs, line)) 
    {
        std::istringstream line_stream(line);
        std::string date;
        double value;
        char sep;
        line_stream >> date >> sep >> value;
        if (line_stream.fail())
        {
            std::cerr << "Failed to extract input.txt: " << line << std::endl;
            continue;
        }
        if (sep != '|') 
        {
			std::cerr << "Error: Sep '|' missing: " << line << std::endl;
			continue;
		}
        if (!checkDate(date)) 
        {
			std::cerr << "Error: Invalid date: " << line << std::endl;
			continue;
		}
		if (!checkValue(value)) 
        {
			continue;
		}
        double price = priceDay(date);
		if (price == -1.0) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::cout << date << " => "  << value << " = " << value * price << std::endl;
	}
}

