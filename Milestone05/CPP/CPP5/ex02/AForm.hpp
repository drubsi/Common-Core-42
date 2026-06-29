#ifndef	AFORM_HPP
#define	AFORM_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class	AForm
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
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	AForm();
	AForm(const std::string& _Name, const int _gradeSign, const int _gradeExecute);
	AForm(const AForm& copy);
	virtual ~AForm();
	AForm& operator=(const AForm& _AForm);

	const std::string&		getName() const;
	bool					getIsSigned() const;
	int						getGradeSign() const;
	int						getGradeExecute() const;
	virtual void			execute(const Bureaucrat& executor) const =0; 
	void 					beSigned(const Bureaucrat& _bureaucrat);
};

	std::ostream& operator<<(std::ostream& out, const AForm& _AForm);

#endif