#include "Harl.hpp"

Harl::Harl(void) {
  std::cout << "An angry Harl has appeared" << std::endl;
}

Harl::~Harl(void) {
  std::cout << "Harl just left" << std::endl;
}

void Harl::_debug( void ){
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::_info( void ){
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning( void ){
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error( void ){
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = 1;
			break ;
		}
  }
  switch (index)
	{
		case 0:
			this->_debug();
			index++;
		case 1:
			this->_info();
			index++;
		case 2:
			this->_warning();
			index++;
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}
