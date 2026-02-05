/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:41:34 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:10:35 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL)
{
}
void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack() const
{
	if (this->weapon == NULL)
		std::cout << this->name << " doesn't have any weapon." << std::endl;
	else
		std::cout << this->name << " attack with their " << weapon->getType() << std::endl;
}