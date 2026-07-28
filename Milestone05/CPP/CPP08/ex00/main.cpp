#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <iterator>//std::distance
#include <cstddef>//std::size_t

int	main(void)
{
	std::vector<int> 			numbersVector;
	std::list<int> 				numbersList;
	std::vector<int>::iterator	result;
	std::list<int>::iterator	resultList;

	for(std::size_t i = 0; i < 100; i++)
	{
		numbersVector.push_back(i + 1);
		numbersList.push_back(i + 100);
	}
	try
	{
			std::cout << "=== Vector container test ===" << std::endl;
			result = easyfind(numbersVector, 99);
			std::cout << "Value to find: 99" << std::endl;
			std::cout << "Index of first occurrence: ";
			std::cout << std::distance(numbersVector.begin(), result) << std::endl;
			std::cout << std::endl;

			std::cout << "=== First occurrence with duplicate values test ===" << std::endl;
			numbersVector.push_back(50);
			result = easyfind(numbersVector, 50);
			std::cout << "Value to find: 50" << std::endl;
			std::cout << "Index of first occurrence: ";
			std::cout << std::distance(numbersVector.begin(), result) << std::endl;
			std::cout << std::endl;

			std::cout << "=== List container test ===" << std::endl;
			resultList = easyfind(numbersList, 100);
			std::cout << "Value to find: 100" << std::endl;
			std::cout << "Index of first occurrence: ";
			std::cout << std::distance(numbersList.begin(), resultList) << std::endl;
			std::cout << std::endl;

			std::cout << "=== Value not found test ===" << std::endl;
			std::cout << "Value to find: 150" << std::endl;
			result = easyfind(numbersVector, 150);
	}
	catch(const std::exception& e)
	{
			std::cout << e.what() << "\n\n";
	}
	try
	{
			std::cout << "=== Empty container test ===" << std::endl;
		numbersVector.clear();
		result = easyfind(numbersVector, 99);	
	}
	catch(const std::exception& e)
	{
			std::cout << e.what() << '\n';
	}
	return (0);
}
