/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:48:40 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:09:20 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int n, std::string name)
{
	Zombie* newZombie = new Zombie[5];
	for (int i = 0; i < n; i++)
	{
		std::cout << "Zombie " << i + 1 << " has created" << std::endl;
		newZombie[i].announce(name);
	}
	return (newZombie);
}