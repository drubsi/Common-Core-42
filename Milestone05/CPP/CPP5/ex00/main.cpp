#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	BureaucratA;
		Bureaucrat	BureaucratB("Fernando", 2);
		Bureaucrat	BureaucratC(BureaucratA);

		std::cout << "\t\t-BureaucratA-" << std::endl;
		std::cout << BureaucratA << std::endl;
		std::cout << "\t\tDecreasing grade." << std::endl;
		BureaucratA.decreaseGrade();
		BureaucratA.decreaseGrade();
		std::cout << BureaucratA << std::endl;
		std::cout << "\n\t\t-BureaucratB-" << std::endl;
		std::cout << BureaucratB << std::endl;
		std::cout << "\t\tAssignment operator: BureaucratB = BureaucratA" << std::endl;
		BureaucratB = BureaucratA;
		std::cout << BureaucratB << std::endl;
		std::cout << "Increasing grade." << std::endl;
		BureaucratB.increaseGrade();
		std::cout << BureaucratB << std::endl;
		std::cout << "\n\t\t-BureaucratC-" << std::endl;
		std::cout << BureaucratC << std::endl;
		std::cout << "Lowest grade limit." << std::endl;
		for(; BureaucratC.getGrade() < 150; BureaucratC.decreaseGrade())
			std::cout << BureaucratC << std::endl;
		std::cout << BureaucratC << std::endl;
		std::cout << "Forcing the exception." << std::endl;
		try
		{
			BureaucratC.decreaseGrade();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Highest grade limit." << std::endl;
		for(; BureaucratC.getGrade() > 1; BureaucratC.increaseGrade())
			std::cout << BureaucratC << std::endl;
		std::cout << BureaucratC << std::endl;
		std::cout << "Forcing the exception." << std::endl;
		BureaucratC.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\t\tAttempting to instantiate with grade 151." << std::endl;
		Bureaucrat	BureaucratD("Lucia", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\t\tAttempting to instantiate with grade 0." << std::endl;
		Bureaucrat	BureaucratE("Mikel", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
