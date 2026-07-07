#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& nameForm, const std::string& targetForm)
{
	AForm*	form;
	std::string internForm[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i;

	for(i = 0; i < 3; i++)
	{
		if (internForm[i] != nameForm)
			continue;
		else
			break;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(targetForm);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return(form);
		case 1:
			form = new RobotomyRequestForm(targetForm);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		case 2:
			form = new PresidentialPardonForm(targetForm);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return(form);
		default:
			std::cout << "Form not found." << std::endl;
			return (NULL);
	}	
}