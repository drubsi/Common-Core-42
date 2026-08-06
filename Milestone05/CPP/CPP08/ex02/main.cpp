#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main()
{
	MutantStack<int> mstack;
			
	std::cout << "MutantStack tests" << std::endl;
	std::cout << "\nInsert and iterate through elements" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

	std::cout << "Top element: " << mstack.top() << std::endl;

	std::cout << "After pop:" << std::endl;
	mstack.pop();
	it = mstack.begin();
	ite = mstack.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "\nReverse iteration through MutantStack" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (ite != it)
	{
		ite--;
		std::cout << *ite << std::endl;
	}
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "\nCopying MutantStack into std::stack" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Top element in std::stack:" << std::endl;
	std::cout << s.top() << std::endl;
	std::cout << "std::stack size:" << std::endl;
	std::cout << s.size() << std::endl;
	MutantStack<int>	copy(mstack);
	MutantStack<int>	b;		
	std::cout << "\nCopy-constructed MutantStack size: " << copy.size() << std::endl;
	it = copy.begin();
	ite = copy.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\nAssignment operator test" << std::endl;
	b = copy;
	it = b.begin();
	ite = b.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\nAdd an element to demonstrate copy independence" << std::endl;
	b.push(42);
	it = b.begin();
	ite = b.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "Assigned MutantStack size: " << b.size() << std::endl;
	std::cout << "\nOriginal copy remains unchanged" << std::endl;
	it = copy.begin();
	ite = copy.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "Copy-constructed MutantStack size: " << copy.size() << std::endl;
	std::cout << "\nEquivalent test with std::list" << std::endl;
	std::list<int>	newList;
	newList.push_back(5);
	newList.push_back(17);
	newList.push_back(3);
	newList.push_back(5);
	newList.push_back(737);
	newList.push_back(0);

	std::list<int>::iterator itList = newList.begin();
	std::list<int>::iterator iteList = newList.end();
	while(itList != iteList)
	{
		std::cout << *itList << std::endl;
		itList++;
	}
	std::cout << "std::list size: " << newList.size() << std::endl;

	std::cout << "Last element: " << newList.back() << std::endl;
	
	std::cout << "After pop_back:" << std::endl;
	newList.pop_back();
	itList = newList.begin();
	iteList = newList.end();
	while(itList != iteList)
	{
		std::cout << *itList << std::endl;
		itList++;
	}
	std::cout << "std::list size: " << newList.size() << std::endl;


	std::cout << "\nReverse iteration through std::list contents:" << std::endl;
	itList = newList.begin();
	iteList = newList.end();
	while (iteList != itList)
	{
		iteList--;
		std::cout << *iteList << std::endl;
	}
	std::cout << "std::list size: " << newList.size() << std::endl;
	return (0);
}
