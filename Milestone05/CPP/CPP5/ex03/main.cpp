#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main (void)
{
	std::srand(std::time(NULL));
	Bureaucrat				permitTechnician("Bill", 137);
	Bureaucrat				executiveClemencyOfficer("Zaphod Beeblebrox", 5);
	Bureaucrat				memoryWiper("Dr. Floppy", 45);
	Bureaucrat				connectorAssistant("Chippy", 150);
	Intern					intern;
	AForm*					defaultFormS;
	AForm*					defaultFormR;
	AForm*					defaultFormP;
	AForm*					defaultFormN;

	/*Name Forms: "shrubbery creation", "robotomy request", "presidential pardon"*/
	defaultFormS = intern.makeForm("shrubbery creation", "home");
	if (defaultFormS)
	{
		permitTechnician.signForm(*defaultFormS);
		permitTechnician.executeForm(*defaultFormS);
		delete defaultFormS;
	}
	defaultFormR = intern.makeForm("robotomy request", "Bender");
	if (defaultFormR)
	{
		memoryWiper.signForm(*defaultFormR);
		memoryWiper.executeForm(*defaultFormR);
		delete defaultFormR;
	}
	defaultFormP = intern.makeForm("presidential pardon", "Bender");
	if (defaultFormP)
	{
		executiveClemencyOfficer.signForm(*defaultFormP);
		executiveClemencyOfficer.executeForm(*defaultFormP);
		delete defaultFormP;
	}
	defaultFormN = intern.makeForm("promotion form", "Bill");
	if (defaultFormN)
	{
		connectorAssistant.signForm(*defaultFormN);
		connectorAssistant.executeForm(*defaultFormN);
		delete defaultFormN;
	}
	return (0);
}