#include "Form.hpp"

Form::Form():name("DEFAULT FORM"), isSigned(0), gradeSign(150), gradeExecute(150)
{
}

Form::Form(const std::string& _name, const int _gradeSign, const int _gradeExecute):name(_name), isSigned(0), gradeSign(_gradeSign), gradeExecute(_gradeExecute)
{
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy):name(copy.getName()), isSigned(copy.getIsSigned()), gradeSign(copy.getGradeSign()), gradeExecute(copy.getGradeExecute())
{
		if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form& Form::operator=(const Form& _Form)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	if (this != &_Form)
		isSigned = _Form.getIsSigned();
	return(*this);
}

const std::string& Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return(isSigned);
}

int Form::getGradeSign() const
{
	return (gradeSign);
}

int Form::getGradeExecute() const
{
	return (gradeExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}

void Form::beSigned(const Bureaucrat& _bureaucrat)
{
	if (_bureaucrat.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		isSigned = true; 
}

std::ostream& operator<<(std::ostream& out, const Form& _Form)
{
	out << "Form name: " << _Form.getName() << "\nBureaucrat grade required to sign: " 
		<< _Form.getGradeSign() << "\nBureaucrat grade required to execute: " << _Form.getGradeExecute() 
		<< "\nForm status: " << _Form.getIsSigned();
	return (out);
}
