#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    int i = 1;
    if (argc < 3)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return (1);
    }
    for (; i < argc; i++) {
		if (std::atoi(argv[i]) <= 0) {
			std::cout << "only positive integers allowed" << std::endl;
            return (1);
		}
    }
    if (i != argc)
    {
		std::cout << "wrong inputs" << std::endl;
	}
    try {
        std::cout << "Before: " ;
        for (int j = 1; j < argc; j++) {
                std::cout << argv[j] << " ";
        }
        std::cout << std::endl;
        PmergeMe PmergeMe(argc - 1, argv);
        PmergeMe.printDeque(argc - 1);
        PmergeMe.printVector(argc - 1);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}