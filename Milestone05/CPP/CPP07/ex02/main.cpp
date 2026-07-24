#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "--- Default construction ---" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	std::cout << "\n--- Construction with size ---" << std::endl;
	Array<int> numbers(5);
	std::cout << "Initial values: ";
	for (std::size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	for (std::size_t i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>((i + 1) * 10);
	std::cout << "Assigned values: ";
	for (std::size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- Copy construction ---" << std::endl;
	Array<int> copied(numbers);
	copied[0] = 999;
	std::cout << "Original first value: " << numbers[0] << std::endl;
	std::cout << "Copied first value:   " << copied[0] << std::endl;

	std::cout << "\n--- Assignment ---" << std::endl;
	Array<int> assigned(2);
	assigned = numbers;
	std::cout << "Assigned array size: " << assigned.size() << std::endl;
	std::cout << "Assigned values: ";
	for (std::size_t i = 0; i < assigned.size(); ++i)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;
	assigned = assigned;
	std::cout << "Size after self-assignment: " << assigned.size() << std::endl;

	std::cout << "\n--- Const access ---" << std::endl;
	const Array<int> constantNumbers(numbers);
	std::cout << "Value read from const Array: "
		<< constantNumbers[2] << std::endl;

	std::cout << "\n--- Different element type ---" << std::endl;
	Array<std::string> words(2);
	words[0] = "Hello";
	words[1] = "templates";
	std::cout << words[0] << " " << words[1] << std::endl;

	std::cout << "\n--- Out-of-bounds access ---" << std::endl;
	try
	{
		numbers[-1] = 0;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	try
	{
		numbers[numbers.size()] = 0;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	try
	{
		empty[0] = 0;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return (0);
}
