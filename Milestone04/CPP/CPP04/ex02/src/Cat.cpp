/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:33 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:32:08 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"),  brain(new ::Brain())
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& cat) : AAnimal(cat), brain(new ::Brain(*cat.brain))
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
		AAnimal::operator=(cat);
		this->brain->operator=(*cat.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miauuuuuu!" << std::endl;
}