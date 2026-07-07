#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main()
{
	Bureaucrat	BureaucratA;
	Bureaucrat	BureaucratB("Pepe", 1);
	Bureaucrat	BureaucratC("Maria", 150);
	Bureaucrat	BureaucratD("John", 13);
	Bureaucrat	BureaucratE(BureaucratD);
	Form		FormA;
	Form		FormB("Form01", 1, 1);
	Form		FormC("Form02", 150, 150);
	Form		FormD("Form03", 3, 7);
	Form		FormE(FormD);
	
	try
	{
		std::cout << "\t\tDefault constructor, copy constructor, and copy assignment operator" << std::endl;
		std::cout << BureaucratA << std::endl;
		std::cout << BureaucratD << std::endl;
		std::cout << BureaucratE << std::endl;
		BureaucratA = BureaucratD;
		std::cout << BureaucratA << std::endl;
		std::cout << BureaucratD << std::endl;
		std::cout << FormA << std::endl;
		std::cout << FormD << std::endl;
		FormA = FormD;
		std::cout << FormA << std::endl;
		std::cout << FormD << std::endl;
		std::cout << "\t\tGrade changes from the highest grade" << std::endl;
		std::cout << BureaucratB << std::endl;
		BureaucratB.decreaseGrade();
		BureaucratB.decreaseGrade();
		std::cout << BureaucratB.getName()<< " " << BureaucratB.getGrade() << std::endl;
		BureaucratB.increaseGrade();
		BureaucratB.increaseGrade();
		std::cout << BureaucratB << std::endl;
		std::cout << "Forcing an increaseGrade() exception" << std::endl;
		BureaucratB.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "\t\tGrade changes from the lowest grade" << std::endl;
		std::cout << BureaucratC << std::endl;
		BureaucratC.increaseGrade();
		BureaucratC.increaseGrade();
		std::cout << BureaucratC << std::endl;
		BureaucratC.decreaseGrade();
		BureaucratC.decreaseGrade();
		std::cout << "Forcing a decreaseGrade() exception" << std::endl;
		BureaucratC.decreaseGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "\t\tForm signing" << std::endl;

		std::cout << BureaucratB << std::endl << std::endl;

		std::cout << FormE << std::endl << std::endl;

		FormE.beSigned(BureaucratB);
		std::cout << FormE << std::endl << std::endl;

		std::cout << FormB << std::endl << std::endl;

		BureaucratB.signForm(FormB);

		std::cout << FormB << std::endl << std::endl;

		std::cout << BureaucratD << std::endl << std::endl;
		
		std::cout << FormD << std::endl << std::endl;

		BureaucratD.signForm(FormD);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << BureaucratD << std::endl << std::endl;
		std::cout << FormD << std::endl << std::endl;
		FormD.beSigned(BureaucratD);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "\t\tConstructor exceptions" << std::endl;
		try
		{
			Bureaucrat	BureaucratF("No_Valid", 0);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << std::endl;
		}
		try
		{
			Bureaucrat	BureaucratG("No_Valid", 151);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << std::endl;
		}
		try
		{
			Form	FormF("No Valid", 0, 0);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << std::endl;
		}
		Form		FormG("No_Valid", 151, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
