/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:26 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/30 10:27:33 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	GenericClap("Atlas");
	ScavTrap	GenericScav("Titan");
	FragTrap	GenericFrag("Nova");
	
	GenericScav.guardGate();
	GenericClap.attack("Titan");
	GenericFrag.attack("Titan");
	GenericFrag.attack("Titan");
	GenericFrag.attack("Titan");
	GenericFrag.attack("Titan");
	GenericScav.takeDamage(120);
	GenericFrag.highFiveGuys();
	
	return (0);
}