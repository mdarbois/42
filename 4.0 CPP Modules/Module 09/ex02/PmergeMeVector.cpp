#include "PmergeMe.hpp"

void PmergeMe::printVector(int arguments) {
	/* std::vector<int>::iterator it = _sortedVector.begin();
	std::cout << "After: ";
	for (; it < _sortedVector.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
   */  std::cout << "Time to process a range of " << arguments << " elements with std::vector : "<< std::fixed
			  << std::setprecision(2)
			  << static_cast<double>(_endVector - _startVector) /
					 (CLOCKS_PER_SEC / 1000000.0)
			  << " us" << std::endl; 
}

int PmergeMe::getUpBoundVector(const std::vector<int>& largeVector, unsigned long range) {
	if (largeVector.size() < static_cast<unsigned long>(range)) {
		return largeVector.size();
	} else
		return static_cast<int>(range);
}

void PmergeMe::BinaryVector(std::vector<int>& largeVector, int value, int range) {
	int low = 0, up = getUpBoundVector(largeVector, range);

	while (low <= up) {
		int middle = low + (up - low) / 2;

		if (largeVector[middle] == value) {
			largeVector.insert(largeVector.begin() + middle + 1, value);
			return;
		} else if (largeVector[middle] < value) {
			low = middle + 1;
		} else
			up = middle - 1;
	}
	largeVector.insert(largeVector.begin() + low, value);
}

unsigned long PmergeMe::getUpIndexVector(const std::vector<int>& smallVector) {
	if (smallVector.size() > 2) 
        return 2;
	return smallVector.size() - 1;
}

unsigned long PmergeMe::getNextUpIndexVector(const std::vector<int>& smallVector, int up) {
	if (getNextJacobsthal(up + 1) > static_cast<int>(smallVector.size()))
		return smallVector.size() - 1;
	return getNextJacobsthal(up + 1) - 1;
}

void PmergeMe::sortJacobsthalVector(std::vector<int>& largeVector, std::vector<int>& smallVector)
{
    unsigned long low = 1, up = getUpIndexVector(smallVector), count = up;

	largeVector.insert(largeVector.begin(), smallVector.at(0));
	for (; low < smallVector.size();) {
		BinaryVector(largeVector, smallVector.at(count), up + low - 1);
		if (count == low) {
			low = up + 1;
			up = getNextUpIndexVector(smallVector, up);
			count = up;
		} else
			count--;
	}
	if (largeVector.front() == -1)
        largeVector.erase(largeVector.begin());
	_sortedVector = largeVector;
}

void PmergeMe::findLimitsVector() {
	std::vector<std::pair<int, int> >::iterator it = _pairVector.begin();
	for (; it < _pairVector.end(); it++) {
		_smallVector.push_back(it->first);
		_largeVector.push_back(it->second);
	}
}

void PmergeMe::mergeVector(std::vector<std::pair<int, int> >& pairVector, int lhs, int middle, int rhs) {
	int left = middle - lhs + 1, right = rhs - middle;
	std::vector<std::pair<int, int> > leftVector(left), rightVector(right);
	for (int i = 0; i < left; ++i) leftVector[i] = pairVector[lhs + i];	  
	for (int j = 0; j < right; ++j) rightVector[j] = pairVector[middle + 1 + j]; 
	int i = 0, j = 0, leftCopy = lhs;

	while (i < left && j < right) {
		if (leftVector[i].second <= rightVector[j].second) {
			pairVector[leftCopy] = leftVector[i++];
		} else
			pairVector[leftCopy] = rightVector[j++];
		leftCopy++;
	}
	while (i < left) pairVector[leftCopy++] = leftVector[i++];
	while (j < right) pairVector[leftCopy++] = rightVector[j++];
}


void PmergeMe::sortLargestVector(std::vector<std::pair<int, int> > &pairVector, int lhs, int rhs)
{
    if (lhs < rhs) {
		int middle = lhs + (rhs - lhs) / 2;
		sortLargestVector(pairVector, lhs, middle);	   
		sortLargestVector(pairVector, middle + 1, rhs); 
		mergeVector(pairVector, lhs, middle, rhs);
	}
}

void PmergeMe::comparePairsVector()
{
	for (std::vector<std::pair<int, int> >::iterator it = _pairVector.begin(); it != _pairVector.end(); it++ )
	{
		if(it->first > it->second)
		{
            std::swap(it->first, it->second);
		}
	}
}

void PmergeMe::splitPairsVector()
{
    std::vector<int>::iterator prev = _mVector.begin(), next = _mVector.begin();

	for (; next < _mVector.end(); next++) {
		if (std::distance(_mVector.begin(), next) % 2 != 0)
			_pairVector.push_back(std::make_pair(*prev, *next));
		prev = next;
	}
    if (_mVector.size() % 2 != 0)
        _pairVector.push_back(std::make_pair(*prev, -1));
}

void PmergeMe::sortVector()
{
    _startVector = clock();
    if (_mVector.size() <= 1)
        return;
    splitPairsVector();
    comparePairsVector();
    sortLargestVector(_pairVector, 0, _pairVector.size() - 1);
    findLimitsVector();
    sortJacobsthalVector(_largeVector, _smallVector);
    _endVector = clock();
}