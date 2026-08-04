#include <iostream>
#include "Span.hpp"
#include <vector>
#include <climits>

int	main()
{
	try
	{
		Span sp(5);

		std::cout << "=== Subject example ===" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	sp;
		std::cout << "\n=== Empty Span test ===" << std::endl;
		try
		{
			std::cout << "shortestSpan(): ";
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << "longestSpan(): ";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	sp(1);
		sp.addNumber(1);
		std::cout << "\n=== Single-number Span test ===" << std::endl;
		try
		{
			std::cout << "shortestSpan(): ";
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << "longestSpan(): ";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span sp(3);
		std::cout << "\n=== Negative values test ===" << std::endl;
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(-1);
		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	sp(5);
		std::vector<int> container;

		std::cout << "\n=== Multiple-number insertion with addNumbers() ===" << std::endl;
		for(std::size_t i = 0; i < 5; i++)
			container.push_back(i + 1);
		sp.addNumbers(container.begin(), container.end());
		std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "\n=== Copy constructor test ===" << std::endl;
		Span	spCopy(sp);
		std::cout << "Original longestSpan(): " << sp.longestSpan() << std::endl;
		std::cout << "Original shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "Copy longestSpan(): " << spCopy.longestSpan() << std::endl;
		std::cout << "Copy shortestSpan(): " << spCopy.shortestSpan() << std::endl;
		try
		{
			std::cout << "\n=== Capacity exceeded addNumber() test ===" << std::endl;
			sp.addNumber(12);
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n=== Capacity exceeded addNumbers() test ===" << std::endl;
		sp.addNumbers(container.begin(), container.end());
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int> container;
		Span	sp(15000);
		Span	sp2(4);
		Span	sp3(4);

		std::cout << "\n=== More than 10,000 numbers test ===" << std::endl;
		for(std::size_t i = 0; i < 15000; i++)
			container.push_back(i + 1);
		sp.addNumbers(container.begin(), container.end());
		std::cout << "Number count: " << container.size() << std::endl;
		std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;
		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "\n=== Extreme span test ===" << std::endl;
		sp2.addNumber(INT_MIN);
		sp2.addNumber(INT_MAX);
		sp2.addNumber(0);
		std::cout << "longestSpan(): " << sp2.longestSpan() << std::endl;
		std::cout << "shortestSpan(): " << sp2.shortestSpan() << std::endl;
		std::cout << "\n=== Assignment operator and independence test ===" << std::endl;
		sp3 = sp2;
		std::cout << "sp2 longestSpan(): " <<  sp2.longestSpan() << std::endl;
		std::cout << "sp2 shortestSpan(): " <<  sp2.shortestSpan() << std::endl;
		std::cout << "sp3 longestSpan(): " <<  sp3.longestSpan() << std::endl;
		std::cout << "sp3 shortestSpan(): " << sp3.shortestSpan() << std::endl;
		sp3.addNumber(3);
		std::cout << "After adding one number to sp3:" << std::endl;
		std::cout << "sp2 longestSpan(): " <<  sp2.longestSpan() << std::endl;
		std::cout << "sp2 shortestSpan(): " << sp2.shortestSpan() << std::endl;
		std::cout << "sp3 longestSpan(): " <<  sp3.longestSpan() << std::endl;
		std::cout << "sp3 shortestSpan(): " << sp3.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
