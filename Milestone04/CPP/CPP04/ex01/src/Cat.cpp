/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:33 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 10:51:04 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"),  brain(new ::Brain())
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat), brain(new ::Brain(*cat.brain))
{
	std::cout << "Cat copy constructor called." << std::endl;
}
Cat::~Cat()
{	
	std::cout << "Cat destructor called." << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		Animal::operator=(cat);
		this->brain->operator=(*cat.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miauuuuuu!" << std::endl;
}