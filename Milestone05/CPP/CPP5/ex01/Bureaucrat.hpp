#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	m_name;
		int					m_grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& _Bureaucrat);

		int	getGrade() const;
		const std::string&	getName() const;

		void increaseGrade();
		void decreaseGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void	signForm(Form& _Form) const;
};
	std::ostream& operator<<(std::ostream& out, const Bureaucrat& _Bureaucrat); 

#endif