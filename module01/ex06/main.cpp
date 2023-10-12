#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
  {
		std::cout << "Sorry i need to understand which level you are currently" << std::endl;
    return (0);
  }
  harl.complain(argv[1]);
	return (0);
}
