#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void showArray(T value)
{
	std::cout << value << " ";
}

template<typename T>
void showConstArray(const T& value)
{
	std::cout << value << " ";
}

template<typename T>
void showArrayModification(T& value)
{
	value *= 10;
	std::cout << value << " ";
}
int	main(void)
{
	std::string array[] = {"Try", "using", "an", "array"};
	const std::string constantArray[] = {"Try", "using", "a", "constant", "array"};
	int	integerArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		
	iter(array, (sizeof(array)/sizeof(array[0])), showArray<std::string>);
	std::cout << std::endl;

	iter(constantArray, (sizeof(constantArray)/sizeof(constantArray[0])), showConstArray<std::string>);
	std::cout << std::endl;

	std::cout << "Trying an array with a size of zero:" << std::endl;
	iter(array, 0, showArray<std::string>);
	std::cout << std::endl;

	std::cout << "\t\t\t Integer array before modification: " << std::endl;
	iter(integerArray, (sizeof(integerArray) / sizeof(integerArray[0])), showArray<int>);

	std::cout << "\n\t\t\t Integer array after modification: " << std::endl;
	iter(integerArray, (sizeof(integerArray) / sizeof(integerArray[0])), showArrayModification<int>);
	std::cout << std::endl;
	return(0);
}