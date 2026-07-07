#ifndef	FORM_HPP
#define	FORM_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Form
{
	private:

		const std::string			name;
		bool						isSigned;
		const int					gradeSign;
		const int					gradeExecute;
	
	public:
	
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
		Form();
		Form(const std::string& _Name, const int _gradeSign, const int _gradeExecute);
		Form(const Form& copy);
		~Form();
		Form& operator=(const Form& _Form);

		const std::string&		getName() const;
		bool					getIsSigned() const;
		int						getGradeSign() const;
		int						getGradeExecute() const;
		void beSigned(const Bureaucrat& _bureaucrat);
};

	std::ostream& operator<<(std::ostream& out, const Form& _Form);

#endif