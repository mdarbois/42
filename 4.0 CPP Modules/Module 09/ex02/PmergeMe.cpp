#include "PmergeMe.hpp"
#include "PmergeMeDeque.cpp"
#include "PmergeMeVector.cpp"

PmergeMe::PmergeMe() {
   std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv) {
    for (int i = 1; i <= argc; i++) {
		this->_mVector.push_back(std::atoi(argv[i]));
        this->_mDeque.push_back(std::atoi(argv[i]));
	}
   //std::cout << "PmergeMe fancy constructor called" << std::endl;
   sortVector();
   sortDeque();
}

PmergeMe::PmergeMe(PmergeMe const &src) {
    this->_mVector = src._mVector;
    this->_mDeque = src._mDeque;
    std::cout << "PmergeMe copy constructor called" << std::endl;
}
  
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs){
        this->_mVector = rhs._mVector;
        this->_mDeque = rhs._mDeque;
    }

  std::cout << "PmergeMe copy assignment operator called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe() {
     // std::cout << "PmergeMe destructor called" << std::endl;
}


int PmergeMe::getNextJacobsthal(int crt) {
	int current = 0, previous = 1, next = crt;

	while (true) {
		next = 2 * current + previous;
		current = previous;
		previous = next;
		if (next > crt) 
            return next;
	}
	return next;
}
