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
		void extractDequeGroup(SortState& state, std::deque<int>& group);
		void orderDequeGroupPair(SortState& state);
		void storeDequePendingGroup(SortState& state);
		void rebuildDequeLevel(SortState& state);
		void buildDequeInsertionGroups(SortState& state);
		void rebuildDequeMainChain(SortState& state);
		void initializeDequeMainChain(SortState& state);
		void insertDequeRemainingGroups(SortState& state);
		void insertDequeGroupByIndex(SortState& state, std::size_t groupIndex);
		std::size_t findDequePartnerGroupIndex(SortState& state,
			std::size_t partnerIndex);
		std::deque<int>::iterator findDequeInsertionPosition(
			int targetRepresentative, SortState& state,
			std::size_t searchEndGroup);
		void insertDequeGroup(SortState& state,
			std::deque<int>::iterator insertionPosition,
			std::size_t groupBegin, std::size_t groupEnd);

		// Vector algorithm
		void fillVector(const InputData& data);
		void sortVectorRecursive();
		void extractVectorGroup(SortState& state, std::vector<int>& group);
		void orderVectorGroupPair(SortState& state);
		void storeVectorPendingGroup(SortState& state);
		void rebuildVectorLevel(SortState& state);
		void buildVectorInsertionGroups(SortState& state);
		void rebuildVectorMainChain(SortState& state);
		void initializeVectorMainChain(SortState& state);
		void insertVectorRemainingGroups(SortState& state);
		void insertVectorGroupByIndex(SortState& state, std::size_t groupIndex);
		std::size_t findVectorPartnerGroupIndex(SortState& state,
			std::size_t partnerIndex);
		std::vector<int>::iterator findVectorInsertionPosition(
			int targetRepresentative, SortState& state, std::size_t searchEndGroup);
		void insertVectorGroup(SortState& state,
			std::vector<int>::iterator insertionPosition, std::size_t vectorGroupBegin,
			std::size_t groupEnd);

		// Shared utilities
		std::size_t jacobsthal(std::size_t currentIndex);	
};

#endif
