/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:48:37 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:09:15 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	this->name = "";
}
Zombie::~Zombie()
{
	std::cout << "zombie " << name << " has deleted." << std::endl;
}
void Zombie::announce(std::string name)
{
	this->name = name;
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}