#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <ctime>
#include <exception>
#include <iomanip>
#include <stdexcept>
#include <utility>

class PmergeMe 
{
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &rhs);
        ~PmergeMe();

        int getNextJacobsthal(int crt);

        void sortDeque();
        void splitPairsDeque();
        void comparePairsDeque();
        void sortLargestDeque(std::deque< std::pair<int, int> > &pairDeque, int lhs, int rhs);
        void mergeDeque(std::deque<std::pair<int, int> >& pairDeque, int lhs, int middle, int rhs);
        void findLimitsDeque();
        void sortJacobsthalDeque(std::deque<int>& largeDeque, std::deque<int>& smallDeque);
        unsigned long getNextUpIndexDeque(const std::deque<int>& smallDeque, int up);
        unsigned long getUpIndexDeque(const std::deque<int>& smallDeque);
        void BinaryDeque(std::deque<int>& largeDeque, int value, int range);
        int getUpBoundDeque(const std::deque<int>& largeDeque, unsigned long range);
        void printDeque(int arguments);

        void sortVector();
        void splitPairsVector();
        void comparePairsVector();
        void sortLargestVector(std::vector< std::pair<int, int> > &pairVector, int lhs, int rhs);
        void mergeVector(std::vector<std::pair<int, int> >& pairVector, int lhs, int middle, int rhs);
        void findLimitsVector();
        void sortJacobsthalVector(std::vector<int>& largeVector, std::vector<int>& smallVector);
        unsigned long getNextUpIndexVector(const std::vector<int>& smallVector, int up);
        unsigned long getUpIndexVector(const std::vector<int>& smallVector);
        void BinaryVector(std::vector<int>& largeVector, int value, int range);
        int getUpBoundVector(const std::vector<int>& largeVector, unsigned long range);
        void printVector(int arguments);

    private:
        clock_t _startDeque;
		std::deque<int>	_mDeque;
        std::deque<std::pair<int, int> > _pairDeque;
	    std::deque<int> _smallDeque;
	    std::deque<int> _largeDeque;
	    std::deque<int> _sortedDeque;
	    clock_t _endDeque;

        clock_t _startVector;
        std::vector<int>	_mVector;
        std::vector<std::pair<int, int> > _pairVector;
	    std::vector<int> _smallVector;
	    std::vector<int> _largeVector;
	    std::vector<int> _sortedVector;
	    clock_t _endVector;

};


#endif