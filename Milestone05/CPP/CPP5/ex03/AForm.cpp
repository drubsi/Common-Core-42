#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():name("DEFAULT AFORM"), isSigned(0), gradeSign(150), gradeExecute(150)
{
}
AForm::AForm(const std::string& _name, const int _gradeSign, const int _gradeExecute):name(_name), isSigned(0), gradeSign(_gradeSign), gradeExecute(_gradeExecute)
{
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHighException();
}
AForm::AForm(const AForm& copy):name(copy.getName()), isSigned(copy.getIsSigned()), gradeSign(copy.getGradeSign()), gradeExecute(copy.getGradeExecute())
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
}
AForm::~AForm()
{
}
AForm& AForm::operator=(const AForm& _AForm)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (this != &_AForm)
		isSigned = _AForm.getIsSigned();
	return(*this);
}

const std::string& AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return(isSigned);
}

int AForm::getGradeSign() const
{
	return (gradeSign);
}

int AForm::getGradeExecute() const
{
	return (gradeExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}
const char* AForm::FormNotSigned::what() const throw()
{
	return("Form is not signed.");
}
void AForm::beSigned(const Bureaucrat& _bureaucrat)
{
	if (_bureaucrat.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		isSigned = true; 
}
void AForm::execute(const Bureaucrat& executor) const
{
		if (getIsSigned() == false)
			throw FormNotSigned();
		else if (executor.getGrade() > getGradeExecute())
			throw GradeTooLowException(); 
}
std::ostream& operator<<(std::ostream& out, const AForm& _AForm)
{
	out << "Form name: " << _AForm.getName() << "\nBureaucrat grade required to sign: " 
		<< _AForm.getGradeSign() << "\nBureaucrat grade required to execute: " << _AForm.getGradeExecute() 
		<< "\nForm status: " << _AForm.getIsSigned();
	return (out);
}