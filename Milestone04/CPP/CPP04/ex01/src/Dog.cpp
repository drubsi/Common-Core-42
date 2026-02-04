/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:36 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 10:48:14 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new ::Brain())
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog), brain(new ::Brain(*dog.brain))
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		Animal::operator=(dog);
		brain->operator=(*dog.brain);
	}
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "guau guau!" << std::endl;
}