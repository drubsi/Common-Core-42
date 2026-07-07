#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern
{
	public:

		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& nameForm, const std::string& formTarget);
};

#endif