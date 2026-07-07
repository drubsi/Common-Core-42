#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target):AForm("Shrubbery Creation Form", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):AForm(copy), target(copy.getTarget())
{
}
 
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return(target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream Myfile((getTarget() + "_shrubbery").c_str());
	Myfile << "       /\\\n";
	Myfile << "      /**\\\n";
	Myfile << "     /****\\\n";
	Myfile << "    /******\\\n";
	Myfile << "   /********\\\n";
	Myfile << "  /**********\\\n";
	Myfile << "      ||\n";
	Myfile << "      ||\n";
	Myfile << "\n";
	Myfile << "        &&\n";
	Myfile << "       &&&\n";
	Myfile << "      &&&&&\n";
	Myfile << "     &&&&&&&\n";
	Myfile << "    &&&&&&&&&\n";
	Myfile << "       |||\n";
	Myfile << "       |||\n";
	Myfile << "\n";
	Myfile << "        /\\\n";
	Myfile << "       /  \\\n";
	Myfile << "      /++++\\\n";
	Myfile << "     /++++++\\\n";
	Myfile << "    /++++++++\\\n";
	Myfile << "   /++++++++++\\\n";
	Myfile << "      ||||\n";
	Myfile << "      ||||\n";
	Myfile.close();
}