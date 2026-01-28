/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:26 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/28 19:33:29 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	Hero("Ulfrid");
	ClapTrap	Antihero(Hero);
	ClapTrap	JohnDoe;
		
	JohnDoe = Hero;
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.takeDamage(2);
	Hero.takeDamage(2);
	Hero.beRepaired(10);
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	Hero.attack("Enemy");
	
	return (0);
}