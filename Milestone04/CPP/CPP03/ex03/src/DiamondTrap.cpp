/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:03:00 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/30 20:00:40 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	name = "";
	ClapTrap::name = name + "_clap_name"; 
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name ),FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Constructor with parameter called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;
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
		HitPoints = diamondTrap.HitPoints;
		EnergyPoints = diamondTrap.EnergyPoints;
		AttackDamage = diamondTrap.AttackDamage;
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