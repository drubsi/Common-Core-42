/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:11:01 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 17:36:38 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
	std::string	name;
	
	public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
};
Zombie*	newZombie(std::string name );
void	randomChump (std::string name);

#endif