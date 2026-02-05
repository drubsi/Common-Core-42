/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:03:00 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:16:44 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	name = "";
	ClapTrap::name = name + "_clap_name"; 
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name ),FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Constructor with parameter called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = diamondTrap.name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl; 
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->name = diamondTrap.name;
		ClapTrap::name = diamondTrap.name + "_clap_name";
		hitPoints = diamondTrap.hitPoints;
		energyPoints = diamondTrap.energyPoints;
		attackDamage = diamondTrap.attackDamage;
	}	
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << " and I am also " << ClapTrap::name << std::endl;
}