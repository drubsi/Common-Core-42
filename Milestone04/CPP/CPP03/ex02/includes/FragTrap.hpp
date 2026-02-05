/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:40:16 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:15:15 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:	
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();
		FragTrap& operator=(const FragTrap& fragTrap);
		void highFiveGuys();
	
};
#endif