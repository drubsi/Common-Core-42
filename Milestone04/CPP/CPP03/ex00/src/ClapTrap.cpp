/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:23 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:13:33 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) 
{
	std::cout << "Constructor with parameters called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
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
		this->hitPoints = clapTrap.hitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->attackDamage = clapTrap.attackDamage;
	}	
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if(this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << name << " has consumed 1 energy point" << std::endl;
	}
	else if (this->hitPoints == 0)
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	else
		std::cout << "ClapTrap " << name << " has 0 EP left." << std::endl;

}

void ClapTrap::takeDamage(const unsigned int amount)
{
	std::cout << "ClapTrap " << name << " take damage, causing " << amount << " points of damage!" << std::endl;
	if (amount >= hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	}
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(const unsigned int amount)
{
	if(this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself, it regains " << amount << " hit points!" << std::endl;
		this->energyPoints--;
		std::cout << "ClapTrap " << name << " has consumed 1 energy point" << std::endl;
	}
	else if (this->hitPoints == 0)
		std::cout << "ClapTrap " << name << " has 0 HP left." << std::endl;
	else 
		std::cout << "ClapTrap " << name << " has 0 EP left." << std::endl;

}
