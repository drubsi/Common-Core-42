#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

struct InputData
{
	std::string input;
};

struct SortState;

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const InputData& data);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

	private:
		std::vector<int> vectorSequence;
		std::deque<int> dequeSequence;
		std::size_t groupSize;

		// Deque algorithm
		void fillDeque(const InputData& data);
		void sortDequeRecursive();
		void extractGroup(SortState& state, std::deque<int>& group);
		void orderGroupPair(SortState& state);
		void storePendingGroup(SortState& state);
		void rebuildDequeLevel(SortState& state);
		void buildInsertionGroups(SortState& state);
		void rebuildMainChain(SortState& state);
		void initializeMainChain(SortState& state);
		void insertRemainingGroups(SortState& state);
		std::size_t findPartnerGroupIndex(SortState& state,
			std::size_t partnerIndex);
		std::deque<int>::iterator findInsertionPosition(
			int targetRepresentative, SortState& state,
			std::size_t searchEndGroup);
		void insertGroup(SortState& state,
			std::deque<int>::iterator insertionPosition,
			std::size_t groupBegin, std::size_t groupEnd);

		// Vector algorithm
		void fillVector(const InputData& data);

		// Shared utilities
		std::size_t jacobsthal(std::size_t currentIndex);
};

#endif
