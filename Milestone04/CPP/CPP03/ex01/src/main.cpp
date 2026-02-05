/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:26 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:14:46 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	GenericClap("Atlas");
	ScavTrap	GenericScav("Titan");
	
	GenericClap.attack("Titan");
	GenericScav.takeDamage(5);
	GenericClap.attack("Titan");
	GenericScav.takeDamage(12);
	GenericScav.attack("Atlas");
	GenericScav.attack("Atlas");
	GenericClap.takeDamage(27);
	GenericScav.beRepaired(27);
	GenericScav.guardGate();
	
	return (0);
}