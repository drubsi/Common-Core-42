/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:30 by drubio-s          #+#    #+#             */
/*   Updated: 2 026/01/31 10:14:35 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal constructor with parameter(s) called" << std::endl;
}
Animal::Animal(const Animal& animal) : type(animal.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& animal)
{
	if (this != &animal)
		this->type = animal.type;
	return(*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "sound" << std::endl;
}