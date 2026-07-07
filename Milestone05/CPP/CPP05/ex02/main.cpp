
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main (void)
{
	std::srand(std::time(NULL));
	Bureaucrat				permitTechnician("Bill", 137);
	Bureaucrat				executiveClemencyOfficer("Zaphod Beeblebrox", 5);
	Bureaucrat				memoryWiper("Dr. Floppy", 45);
	Bureaucrat				connectorAssistant("Chippy", 150);
	ShrubberyCreationForm	homeForm("home");
	RobotomyRequestForm		form300X("Bender");
	PresidentialPardonForm	pardon("Bender");
	
	std::cout << "\t\t FORM" << std::endl;
	std::cout << homeForm << std::endl;
	std::cout << "\n\t\t BUREAUCRAT" << std::endl;
	std::cout << connectorAssistant << std::endl;
	try
	{
		connectorAssistant.signForm(homeForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\t\t BUREAUCRAT" << std::endl;
	std::cout << permitTechnician << std::endl;
	permitTechnician.signForm(homeForm);
	permitTechnician.executeForm(homeForm);
	std::cout << std::endl;
	std::cout << "\t\t FORM" << std::endl;
	std::cout << pardon << std::endl;
	std::cout << "\n\t\t BUREAUCRAT" << std::endl;
	std::cout << connectorAssistant << std::endl;
	try
	{
		pardon.execute(connectorAssistant);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "\t\t FORM" << std::endl;
		std::cout << form300X << std::endl;
		std::cout << "\n\t\t BUREAUCRAT" << std::endl;
		std::cout << memoryWiper << std::endl;
		memoryWiper.signForm(form300X);
		if (std::rand() % 2 == 0)
		{
			std::cout << std::endl;
			std::cout << "\t\t FORM" << std::endl;
			std::cout << pardon << std::endl;
			std::cout << "\n\t\t BUREAUCRAT" << std::endl;
			std::cout << executiveClemencyOfficer << std::endl;
			executiveClemencyOfficer.signForm(pardon);
			executiveClemencyOfficer.executeForm(pardon);
		}
		else
			form300X.execute(memoryWiper);
	}
	return (0);
}