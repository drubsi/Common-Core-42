#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target):AForm("Presidential Pardon Form", 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):AForm(copy), target(copy.getTarget())
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return(target);
}
