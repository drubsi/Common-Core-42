/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:23 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/28 19:41:41 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "";
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) 
{
	std::cout << "Constructor with parameters called" << std::endl;
	this->name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor " << name << " called" << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	if (this != &clapTrap)
	{
		this->name = clapTrap.name;
		this->HitPoints = clapTrap.HitPoints;
		this->EnergyPoints = clapTrap.EnergyPoints;
		this->AttackDamage = clapTrap.AttackDamage;
	}	
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
		std::cout << "ClapTrap " << name << " has consumed 1 energy point" << std::endl;
	}
	else if (this->HitPoints == 0)
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	else
		std::cout << "ClapTrap " << name << " has 0 EP left." << std::endl;

}

void ClapTrap::takeDamage(const unsigned int amount)
{
	std::cout << "ClapTrap " << name << " take damage, causing " << amount << " points of damage!" << std::endl;
	if (amount >= HitPoints)
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	}
	else
		this->HitPoints -= amount;
}

void ClapTrap::beRepaired(const unsigned int amount)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->HitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself, it regains " << amount << " hit points!" << std::endl;
		this->EnergyPoints--;
		std::cout << "ClapTrap " << name << " has consumed 1 energy point" << std::endl;
	}
	else if (this->HitPoints == 0)
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	else 
		std::cout << "ClapTrap " << name << " has 0 EP left." << std::endl;

}
