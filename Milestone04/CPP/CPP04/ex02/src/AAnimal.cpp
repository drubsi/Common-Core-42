/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:30 by drubio-s          #+#    #+#             */
/*   Updated: 2 026/01/31 10:14:35 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
	std::cout << "AAnimal constructor with parameter(s) called" << std::endl;
}
AAnimal::AAnimal(const AAnimal& animal) : type(animal.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& animal)
{
	if (this != &animal)
		this->type = animal.type;
	return(*this);
}

std::string AAnimal::getType() const
{
	return (this->type);
}
