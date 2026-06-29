#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():m_name("BureaucratX"), m_grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):m_name(name), m_grade(grade)
{
	if (m_grade > 150)
		throw GradeTooLowException();
	else if (m_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):m_name(copy.m_name), m_grade(copy.m_grade)
{
	if (m_grade > 150)
		throw GradeTooLowException();
	else if (m_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& _Bureaucrat)
{
	if (_Bureaucrat.m_grade > 150)
		throw GradeTooLowException();
	else if (_Bureaucrat.m_grade < 1)
		throw GradeTooHighException();
	if (this != &_Bureaucrat)
	m_grade = _Bureaucrat.getGrade()
		;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return(m_grade);
}

const std::string& Bureaucrat::getName() const
{
	return(m_name);
}

void Bureaucrat::increaseGrade()
{
	if (m_grade == 1)
		throw GradeTooHighException();
	m_grade--;	
}

void Bureaucrat::decreaseGrade()
{
	if (m_grade == 150)
		throw GradeTooLowException();
	m_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high (grade number below 1).");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low (grade number above 150).");
}

void	Bureaucrat::signForm(AForm& _Aform) const
{
	try
	{
		_Aform.beSigned(*this);
		std::cout << getName() << " signed " << _Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << _Aform.getName() <<  " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& _Aform) const
{
	try
	{
		_Aform.execute(*this);
		std::cout << getName() << " executed " << _Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << _Aform.getName() 
			<< " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& _Bureaucrat)
{
	out << _Bureaucrat.getName() << ", bureaucrat grade " << _Bureaucrat.getGrade() << ".";
	return (out);
}