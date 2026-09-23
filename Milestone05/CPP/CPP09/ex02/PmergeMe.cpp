#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>

struct SortState
{
	bool hasPending;
	std::size_t currentGroupSize;
	std::size_t completeGroups;
	std::size_t groupPairs;
	std::size_t unpairedGroup;
	std::deque<int> groupA;
	std::deque<int> groupB;
	std::deque<int> pending;
	std::deque<int> dequeTemp;

	SortState(std::size_t activeSize, std::size_t initialGroupSize)
		: hasPending(false), currentGroupSize(initialGroupSize),
		  completeGroups(activeSize / initialGroupSize),
		  groupPairs(completeGroups / 2),
		  unpairedGroup(completeGroups % 2), groupA(), groupB(), pending(),
		  dequeTemp()
	{
		if (unpairedGroup)
			hasPending = true;
	}
};

PmergeMe::PmergeMe()
	: vectorSequence(0), dequeSequence(0), groupSize(1)
{
}

PmergeMe::PmergeMe(const InputData& data)
	: vectorSequence(0), dequeSequence(0), groupSize(1)
{
	fillDeque(data);
	sortDequeRecursive();
	std::cout << "After: " << std::endl;
	for (std::size_t index = 0; index < dequeSequence.size(); index++)
		std::cout << dequeSequence.at(index) << " ";
	std::cout << std::endl;
	fillVector(data);
}

PmergeMe::PmergeMe(const PmergeMe& copy)
	: vectorSequence(copy.vectorSequence), dequeSequence(copy.dequeSequence),
	  groupSize(copy.groupSize)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vectorSequence = other.vectorSequence;
		dequeSequence = other.dequeSequence;
		groupSize = other.groupSize;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::fillDeque(const InputData& data)
{
	std::istringstream converter(data.input);
	int value = 0;

	while (converter >> value)
		dequeSequence.push_back(value);
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
		extractGroup(state, state.groupA);
		extractGroup(state, state.groupB);
		orderGroupPair(state);
		state.groupA.clear();
		state.groupB.clear();
	}
	storePendingGroup(state);
	state.dequeTemp = dequeSequence;
	groupSize *= 2;
	sortDequeRecursive();
	rebuildDequeLevel(state);
}

void PmergeMe::extractGroup(SortState& state, std::deque<int>& group)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		group.push_back(state.dequeTemp.at(index));
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		state.dequeTemp.pop_front();
}

void PmergeMe::orderGroupPair(SortState& state)
{
	if (state.groupA.at(state.currentGroupSize - 1)
		> state.groupB.at(state.currentGroupSize - 1))
	{
		for (std::deque<int>::iterator it = state.groupB.begin();
			it != state.groupB.end(); it++)
			dequeSequence.push_back(*it);
		for (std::deque<int>::iterator it = state.groupA.begin();
			it != state.groupA.end(); it++)
			dequeSequence.push_back(*it);
	}
	else
	{
		for (std::deque<int>::iterator it = state.groupA.begin();
			it != state.groupA.end(); it++)
			dequeSequence.push_back(*it);
		for (std::deque<int>::iterator it = state.groupB.begin();
			it != state.groupB.end(); it++)
			dequeSequence.push_back(*it);
	}
}

void PmergeMe::storePendingGroup(SortState& state)
{
	if (state.hasPending)
	{
		state.pending = state.dequeTemp;
		state.dequeTemp.clear();
	}
}

void PmergeMe::rebuildDequeLevel(SortState& state)
{
	if (state.groupPairs > 1 || !state.pending.empty())
	{
		state.dequeTemp = dequeSequence;
		dequeSequence.clear();
		buildInsertionGroups(state);
		rebuildMainChain(state);
	}
}

void PmergeMe::buildInsertionGroups(SortState& state)
{
	for (std::size_t groupIndex = 0; groupIndex < state.groupPairs;
		groupIndex++)
	{
		extractGroup(state, state.groupB);
		extractGroup(state, state.groupA);
		if (state.dequeTemp.empty() && state.hasPending)
		{
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.groupB.push_back(state.pending.at(index));
			for (std::size_t index = 0; index < state.currentGroupSize;
				index++)
				state.pending.pop_back();
		}
	}
}

void PmergeMe::rebuildMainChain(SortState& state)
{
	initializeMainChain(state);
	insertRemainingGroups(state);
}

void PmergeMe::initializeMainChain(SortState& state)
{
	for (std::size_t index = 0; index < state.currentGroupSize; index++)
		dequeSequence.push_back(state.groupB.at(index));
	for (std::size_t index = 0; index < state.groupA.size(); index++)
		dequeSequence.push_back(state.groupA.at(index));
}

void PmergeMe::insertRemainingGroups(SortState& state)
{
	std::size_t previousBoundary = 1;
	std::size_t jacobsthalIndex = 3;
	std::size_t totalPendingGroups
		= state.groupB.size() / state.currentGroupSize;

	while (previousBoundary < totalPendingGroups)
	{
		std::size_t currentBoundary = jacobsthal(jacobsthalIndex);
		if (currentBoundary > totalPendingGroups)
			currentBoundary = totalPendingGroups;
		for (std::size_t groupIndex = currentBoundary;
			groupIndex > previousBoundary; groupIndex--)
		{
			std::size_t groupBegin
				= (groupIndex - 1) * state.currentGroupSize;
			std::size_t groupEnd
				= groupIndex * state.currentGroupSize - 1;
			std::size_t partnerGroupIndex
				= findPartnerGroupIndex(state, groupEnd);
			std::deque<int>::iterator insertionPosition
				= findInsertionPosition(state.groupB.at(groupEnd), state,
					partnerGroupIndex);
			insertGroup(state, insertionPosition, groupBegin, groupEnd);
		}
		previousBoundary = currentBoundary;
		jacobsthalIndex++;
	}
}

std::size_t PmergeMe::findPartnerGroupIndex(SortState& state,
	std::size_t partnerIndex)
{
	std::size_t position = 0;

	if (partnerIndex >= state.groupA.size())
		return (dequeSequence.size() / state.currentGroupSize);
	while (dequeSequence.at(position) != state.groupA.at(partnerIndex))
		position++;
	return (position / state.currentGroupSize);
}

std::deque<int>::iterator PmergeMe::findInsertionPosition(
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
		if (targetRepresentative < dequeSequence.at(representativeIndex))
			searchEndGroup = middleGroup;
		else
			searchBeginGroup = middleGroup + 1;
	}
	insertionPosition += searchBeginGroup * state.currentGroupSize;
	return (insertionPosition);
}

void PmergeMe::insertGroup(SortState& state,
	std::deque<int>::iterator insertionPosition, std::size_t groupBegin,
	std::size_t groupEnd)
{
	std::deque<int>::iterator rangeBegin
		= state.groupB.begin() + groupBegin;
	std::deque<int>::iterator rangeEnd
		= state.groupB.begin() + groupEnd + 1;

	dequeSequence.insert(insertionPosition, rangeBegin, rangeEnd);
}

void PmergeMe::fillVector(const InputData& data)
{
	std::istringstream converter(data.input);
	int value = 0;

	while (converter >> value)
		vectorSequence.push_back(value);
}

std::size_t PmergeMe::jacobsthal(std::size_t currentIndex)
{
	if (currentIndex <= 1)
		return (currentIndex);
	return (jacobsthal(currentIndex - 1)
		+ 2 * jacobsthal(currentIndex - 2));
}
