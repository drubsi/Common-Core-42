/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:26 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:15:51 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	GenericClap("Atlas");
	ScavTrap	GenericScav("Titan");
	FragTrap	GenericFrag("Nova");
	FragTrap	GenericFrag2(GenericFrag);
	
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