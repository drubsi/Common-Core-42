/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:49:22 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/19 18:03:03 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& c) :name(name), weapon(c)
{
}
void HumanA::attack() const
{
	std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}