#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <climits>
#include <stdexcept>

struct SortState
{
	bool hasPending;
	std::size_t currentGroupSize;
	std::size_t completeGroups;
	std::size_t groupPairs;
	std::size_t unpairedGroup;
	std::deque<int> dequeGroupA;
	std::deque<int> dequeGroupB;
	std::deque<int> dequePending;
	std::deque<int> dequeTemp;
	std::vector<int> vectorGroupA;
	std::vector<int> vectorGroupB;
	std::vector<int> vectorPending;
	std::vector<int> vectorTemp;


	SortState(std::size_t activeSize, std::size_t initialGroupSize)
		: hasPending(false), currentGroupSize(initialGroupSize),
		  completeGroups(activeSize / initialGroupSize),
		  groupPairs(completeGroups / 2),
		  unpairedGroup(completeGroups % 2), dequeGroupA(), dequeGroupB(), dequePending(),
		  dequeTemp(), vectorGroupA(), vectorGroupB(), vectorPending(), vectorTemp()
	{
		if (unpairedGroup)
			hasPending = true;
	}
};

PmergeMe::PmergeMe()
	: vectorSequence(0), dequeSequence(0), groupSize(1), dequeComparisons(0),
	  vectorComparisons(0)
{
}

PmergeMe::PmergeMe(const InputData& data)
	: vectorSequence(0), dequeSequence(0), groupSize(1), dequeComparisons(0),
	  vectorComparisons(0)
{
	std::clock_t	dequeStart = std::clock();
	fillDeque(data);
	sortDequeRecursive();
	std::clock_t	dequeEnd = std::clock();
	groupSize = 1;
	std::clock_t	VectorStart = std::clock();
	fillVector(data);
	sortVectorRecursive();
	std::clock_t	VectorEnd = std::clock();
	double	timemsDeque = (dequeEnd - dequeStart) * 1000000.0 / CLOCKS_PER_SEC;
	double	timemsVector = (VectorEnd - VectorStart)  * 1000000.0 / CLOCKS_PER_SEC;
	printBefore(data);
	printResult(timemsDeque, timemsVector);
	//printComparisonCounts();
}

PmergeMe::PmergeMe(const PmergeMe& copy)
	: vectorSequence(copy.vectorSequence), dequeSequence(copy.dequeSequence),
	  groupSize(copy.groupSize), dequeComparisons(copy.dequeComparisons),
	  vectorComparisons(copy.vectorComparisons)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vectorSequence = other.vectorSequence;
		dequeSequence = other.dequeSequence;
		groupSize = other.groupSize;
		dequeComparisons = other.dequeComparisons;
		vectorComparisons = other.vectorComparisons;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printComparisonCounts() const
{
	std::cout << "Value comparisons with std::deque: "
		<< dequeComparisons << std::endl;
	std::cout << "Value comparisons with std::vector: "
		<< vectorComparisons << std::endl;
}

void PmergeMe::printBefore(const InputData data)
{
	std::cout << "Before: ";
	bool space = false;
	for(std::string::const_iterator it = data.input.begin(); it < data.input.end(); it++)
	{
		if(std::isspace(*it) && !space)
			space = true;
		else if(std::isspace(*it) && space)
			continue;
		else if(std::isdigit(*it))
			space = false;
		std::cout << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::printResult(double timeDeque, double timeVector)
{
	std::cout << "After: ";
	for(std::size_t index = 0; index < vectorSequence.size(); index++)
	{
		std::cout << vectorSequence.at(index);
		if(index != vectorSequence.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << dequeSequence.size() << " elements with std::deque : "<< std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::vector : "<< std::fixed << std::setprecision(5) << timeVector << " us" << std::endl;
}

void PmergeMe::fillDeque(const InputData& data)
{
	std::istringstream converter(data.input);
	long value = 0;
	int	finalValue = 0;
	std::string firstConversion;

	while (converter >> firstConversion)
	{
		std::istringstream secondConversion(firstConversion);
		secondConversion >> value;
				if(!secondConversion.eof() || secondConversion.fail())
			throw std::invalid_argument("Error.");

		if(value <= 0 || value > INT_MAX)
			throw std::invalid_argument("Error.");
		finalValue = value;
		dequeSequence.push_back(finalValue);
	}
}

void PmergeMe::sortDequeRecursive()
{
	SortState state(dequeSequence.size(), groupSize);

	if (state.groupPairs < 1)
		return;
	state.dequeTemp = dequeSequence;
	dequeSequence.clear();
	for (std::size_t groupIndex = 0; groupIndex < state.groupPairs;
		groupIndex++)
	{
		extractDequeGroup(state, state.dequeGroupA);
		extractDequeGroup(state, state.dequeGroupB);
		orderDequeGroupPair(state);
		state.dequeGroupA.clear();
		state.dequeGroupB.clear();
	}
	storeDequePendingGroup(state);
	state.dequeTemp = dequeSequence;
	groupSize *= 2;
	sortDequeRecursive();
	rebuildDequeLevel(state);
}

void PmergeMe::extractDequeGroup(SortState& state, std::deque<int>& group)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		group.push_back(state.dequeTemp.at(index));
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		state.dequeTemp.pop_front();
}

void PmergeMe::orderDequeGroupPair(SortState& state)
{
	dequeComparisons++;
	if (state.dequeGroupA.at(state.currentGroupSize - 1)
		> state.dequeGroupB.at(state.currentGroupSize - 1))
	{
		for (std::deque<int>::iterator it = state.dequeGroupB.begin();
			it != state.dequeGroupB.end(); it++)
			dequeSequence.push_back(*it);
		for (std::deque<int>::iterator it = state.dequeGroupA.begin();
			it != state.dequeGroupA.end(); it++)
			dequeSequence.push_back(*it);
	}
	else
	{
		for (std::deque<int>::iterator it = state.dequeGroupA.begin();
			it != state.dequeGroupA.end(); it++)
			dequeSequence.push_back(*it);
		for (std::deque<int>::iterator it = state.dequeGroupB.begin();
			it != state.dequeGroupB.end(); it++)
			dequeSequence.push_back(*it);
	}
}

void PmergeMe::storeDequePendingGroup(SortState& state)
{
	if (state.hasPending)
	{
		state.dequePending = state.dequeTemp;
		state.dequeTemp.clear();
	}
}

void PmergeMe::rebuildDequeLevel(SortState& state)
{
	if (state.groupPairs > 1 || !state.dequePending.empty())
	{
		state.dequeTemp = dequeSequence;
		dequeSequence.clear();
		buildDequeInsertionGroups(state);
		rebuildDequeMainChain(state);
	}
}

void PmergeMe::buildDequeInsertionGroups(SortState& state)
{
	for (std::size_t groupIndex = 0; groupIndex < state.groupPairs;
		groupIndex++)
	{
		extractDequeGroup(state, state.dequeGroupB);
		extractDequeGroup(state, state.dequeGroupA);
		if (state.dequeTemp.empty() && state.hasPending)
		{
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.dequeGroupB.push_back(state.dequePending.at(index));
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.dequePending.pop_back();
		}
	}
}

void PmergeMe::rebuildDequeMainChain(SortState& state)
{
	initializeDequeMainChain(state);
	insertDequeRemainingGroups(state);
}

void PmergeMe::initializeDequeMainChain(SortState& state)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		dequeSequence.push_back(state.dequeGroupB.at(index));
	for (std::size_t index = 0; index < state.dequeGroupA.size(); index++)
		dequeSequence.push_back(state.dequeGroupA.at(index));
}

void PmergeMe::insertDequeRemainingGroups(SortState& state)
{
	std::size_t previousBoundary = 1;
	std::size_t jacobsthalIndex = 3;
	std::size_t totalPendingGroups
		= state.dequeGroupB.size() / state.currentGroupSize;

	while (previousBoundary < totalPendingGroups)
	{
		std::size_t currentBoundary = jacobsthal(jacobsthalIndex);
		if (currentBoundary > totalPendingGroups)
			currentBoundary = totalPendingGroups;
		for (std::size_t groupIndex = currentBoundary;
			groupIndex > previousBoundary; groupIndex--)
		{
			insertDequeGroupByIndex(state, groupIndex);
		}
		previousBoundary = currentBoundary;
		jacobsthalIndex++;
	}
}

void PmergeMe::insertDequeGroupByIndex(SortState& state, std::size_t groupIndex)
{	
	std::size_t dequeGroupBegin = (groupIndex - 1) * state.currentGroupSize;
	std::size_t groupEnd = groupIndex * state.currentGroupSize - 1;
	std::size_t partnerGroupIndex = findDequePartnerGroupIndex(state, groupEnd);
	std::deque<int>::iterator insertionPosition	= findDequeInsertionPosition(state.dequeGroupB.at(groupEnd), state, partnerGroupIndex);
	insertDequeGroup(state, insertionPosition, dequeGroupBegin, groupEnd);
}

std::size_t PmergeMe::findDequePartnerGroupIndex(SortState& state,
	std::size_t partnerIndex)
{
	std::size_t position = 0;

	if (partnerIndex >= state.dequeGroupA.size())
		return (dequeSequence.size() / state.currentGroupSize);
	while (dequeSequence.at(position) != state.dequeGroupA.at(partnerIndex))
		position++;
	return (position / state.currentGroupSize);
}

std::deque<int>::iterator PmergeMe::findDequeInsertionPosition(
	int targetRepresentative, SortState& state, std::size_t searchEndGroup)
{
	std::size_t searchBeginGroup = 0;
	std::deque<int>::iterator insertionPosition = dequeSequence.begin();

	while (searchBeginGroup < searchEndGroup)
	{
		std::size_t middleGroup
			= searchBeginGroup + (searchEndGroup - searchBeginGroup) / 2;
		std::size_t representativeIndex
			= middleGroup * state.currentGroupSize
			+ state.currentGroupSize - 1;
		dequeComparisons++;
		if (targetRepresentative < dequeSequence.at(representativeIndex))
			searchEndGroup = middleGroup;
		else
			searchBeginGroup = middleGroup + 1;
	}
	insertionPosition += searchBeginGroup * state.currentGroupSize;
	return (insertionPosition);
}

void PmergeMe::insertDequeGroup(SortState& state,
	std::deque<int>::iterator insertionPosition, std::size_t dequeGroupBegin,
	std::size_t groupEnd)
{
	std::deque<int>::iterator rangeBegin
		= state.dequeGroupB.begin() + dequeGroupBegin;
	std::deque<int>::iterator rangeEnd
		= state.dequeGroupB.begin() + groupEnd + 1;

	dequeSequence.insert(insertionPosition, rangeBegin, rangeEnd);
}

void PmergeMe::fillVector(const InputData& data)
{
	std::istringstream converter(data.input);
	long value = 0;
	int	finalValue = 0;
	std::string firstConversion;

	while (converter >> firstConversion)
	{
		std::istringstream secondConversion(firstConversion);
		secondConversion >> value;
		if(!secondConversion.eof() || secondConversion.fail())
			throw std::invalid_argument("Error.");

		if(value <= 0 || value > INT_MAX)
			throw std::invalid_argument("Error.");
		finalValue = value;
		vectorSequence.push_back(finalValue);
	}
}

std::size_t PmergeMe::jacobsthal(std::size_t currentIndex)
{
	if (currentIndex <= 1)
		return (currentIndex);
	return (jacobsthal(currentIndex - 1)
		+ 2 * jacobsthal(currentIndex - 2));
}

void PmergeMe::sortVectorRecursive()
{
	SortState state(vectorSequence.size(), groupSize);

	if (state.groupPairs < 1)
		return;
	state.vectorTemp = vectorSequence;
	vectorSequence.clear();
	for (std::size_t groupIndex = 0; groupIndex < state.groupPairs;
		groupIndex++)
	{
		extractVectorGroup(state, state.vectorGroupA);
		extractVectorGroup(state, state.vectorGroupB);
		orderVectorGroupPair(state);
		state.vectorGroupA.clear();
		state.vectorGroupB.clear();
	}
	storeVectorPendingGroup(state);
	state.vectorTemp = vectorSequence;
	groupSize *= 2;
	sortVectorRecursive();
	rebuildVectorLevel(state);
}
void PmergeMe::extractVectorGroup(SortState& state, std::vector<int>& group)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		group.push_back(state.vectorTemp.at(index));
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		state.vectorTemp.erase(state.vectorTemp.begin());
}
void PmergeMe::orderVectorGroupPair(SortState& state)
{
	vectorComparisons++;
	if (state.vectorGroupA.at(state.currentGroupSize - 1)
		> state.vectorGroupB.at(state.currentGroupSize - 1))
	{
		for (std::vector<int>::iterator it = state.vectorGroupB.begin();
			it != state.vectorGroupB.end(); it++)
			vectorSequence.push_back(*it);
		for (std::vector<int>::iterator it = state.vectorGroupA.begin();
			it != state.vectorGroupA.end(); it++)
			vectorSequence.push_back(*it);
	}
	else
	{
		for (std::vector<int>::iterator it = state.vectorGroupA.begin();
			it != state.vectorGroupA.end(); it++)
			vectorSequence.push_back(*it);
		for (std::vector<int>::iterator it = state.vectorGroupB.begin();
			it != state.vectorGroupB.end(); it++)
			vectorSequence.push_back(*it);
	}
}

void PmergeMe::storeVectorPendingGroup(SortState& state)
{
	if (state.hasPending)
	{
		state.vectorPending = state.vectorTemp;
		state.vectorTemp.clear();
	}
}

void PmergeMe::rebuildVectorLevel(SortState& state)
{
	if (state.groupPairs > 1 || !state.vectorPending.empty())
	{
		state.vectorTemp = vectorSequence;
		vectorSequence.clear();
		buildVectorInsertionGroups(state);
		rebuildVectorMainChain(state);
	}
}

void PmergeMe::buildVectorInsertionGroups(SortState& state)
{
	for (std::size_t groupIndex = 0; groupIndex < state.groupPairs;
		groupIndex++)
	{
		extractVectorGroup(state, state.vectorGroupB);
		extractVectorGroup(state, state.vectorGroupA);
		if (state.vectorTemp.empty() && state.hasPending)
		{
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.vectorGroupB.push_back(state.vectorPending.at(index));
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.vectorPending.pop_back();
		}
	}
}

void PmergeMe::rebuildVectorMainChain(SortState& state)
{
	initializeVectorMainChain(state);
	insertVectorRemainingGroups(state);
}

void PmergeMe::initializeVectorMainChain(SortState& state)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		vectorSequence.push_back(state.vectorGroupB.at(index));
	for (std::size_t index = 0; index < state.vectorGroupA.size(); index++)
		vectorSequence.push_back(state.vectorGroupA.at(index));
}

void PmergeMe::insertVectorRemainingGroups(SortState& state)
{
	std::size_t previousBoundary = 1;
	std::size_t jacobsthalIndex = 3;
	std::size_t totalPendingGroups
		= state.vectorGroupB.size() / state.currentGroupSize;

	while (previousBoundary < totalPendingGroups)
	{
		std::size_t currentBoundary = jacobsthal(jacobsthalIndex);
		if (currentBoundary > totalPendingGroups)
			currentBoundary = totalPendingGroups;
		for (std::size_t groupIndex = currentBoundary;
			groupIndex > previousBoundary; groupIndex--)
		{
			insertVectorGroupByIndex(state, groupIndex);
		}
		previousBoundary = currentBoundary;
		jacobsthalIndex++;
	}
}

void PmergeMe::insertVectorGroupByIndex(SortState& state, std::size_t groupIndex)
{
	std::size_t vectorGroupBegin = (groupIndex - 1) * state.currentGroupSize;
	std::size_t groupEnd = groupIndex * state.currentGroupSize - 1;
	std::size_t partnerGroupIndex = findVectorPartnerGroupIndex(state, groupEnd);
	std::vector<int>::iterator insertionPosition	= findVectorInsertionPosition(state.vectorGroupB.at(groupEnd), state, partnerGroupIndex);
	insertVectorGroup(state, insertionPosition, vectorGroupBegin, groupEnd);
}

std::size_t PmergeMe::findVectorPartnerGroupIndex(SortState& state,
	std::size_t partnerIndex)
{
	std::size_t position = 0;

	if (partnerIndex >= state.vectorGroupA.size())
		return (vectorSequence.size() / state.currentGroupSize);
	while (vectorSequence.at(position) != state.vectorGroupA.at(partnerIndex))
		position++;
	return (position / state.currentGroupSize);
}

std::vector<int>::iterator PmergeMe::findVectorInsertionPosition(
	int targetRepresentative, SortState& state, std::size_t searchEndGroup)
{
	std::size_t searchBeginGroup = 0;
	std::vector<int>::iterator insertionPosition = vectorSequence.begin();

	while (searchBeginGroup < searchEndGroup)
	{
		std::size_t middleGroup
			= searchBeginGroup + (searchEndGroup - searchBeginGroup) / 2;
		std::size_t representativeIndex
			= middleGroup * state.currentGroupSize
			+ state.currentGroupSize - 1;
		vectorComparisons++;
		if (targetRepresentative < vectorSequence.at(representativeIndex))
			searchEndGroup = middleGroup;
		else
			searchBeginGroup = middleGroup + 1;
	}
	insertionPosition += searchBeginGroup * state.currentGroupSize;
	return (insertionPosition);
}

void PmergeMe::insertVectorGroup(SortState& state,
	std::vector<int>::iterator insertionPosition, std::size_t vectorGroupBegin,
	std::size_t groupEnd)
{
	std::vector<int>::iterator rangeBegin
		= state.vectorGroupB.begin() + vectorGroupBegin;
	std::vector<int>::iterator rangeEnd
		= state.vectorGroupB.begin() + groupEnd + 1;

	vectorSequence.insert(insertionPosition, rangeBegin, rangeEnd);
}
