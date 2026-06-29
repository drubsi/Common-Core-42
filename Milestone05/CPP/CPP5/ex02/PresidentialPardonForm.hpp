#ifndef	PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		std::string	target;

	public:
	
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute(const Bureaucrat& executor) const ;
		const std::string& getTarget() const;
};

#endif