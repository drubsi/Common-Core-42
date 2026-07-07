#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target):AForm("Robotomy Request Form", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):AForm(copy) ,target(copy.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << "* drilling noises *" << std::endl;
	std::cout << "DRRRRRR... CLANK! CLANK! BZZZZZ..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " robotomy failed." << std::endl;
	else
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
}