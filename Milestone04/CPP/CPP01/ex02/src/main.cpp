/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:38:55 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/13 10:22:56 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "The memory address of the string variable:\n" << &str << std::endl;
	std::cout << "The memory address held by stringPTR:\n" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:\n" << &stringREF << std::endl;
	std::cout << "Value of the string variable:\n" << str << std::endl;
	std::cout << "Value pointed to by stringPTR:\n" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\n" << stringREF << std::endl;
	return (0);
}