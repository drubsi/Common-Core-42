/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:24:19 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/28 19:28:36 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class	ClapTrap
{
	private:
		std::string	name;
		unsigned int			HitPoints;
		unsigned int			EnergyPoints;
		unsigned int			AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& clapTrap);
		void attack(const std::string& target);
		void takeDamage(const unsigned int amount);
		void beRepaired(const unsigned int amount);
		
};

#endif